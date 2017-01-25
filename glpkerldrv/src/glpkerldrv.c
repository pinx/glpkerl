#include "config.h"
#undef ERL_SYS_DRV

#include <errno.h>
#include <erl_driver.h>
#include <float.h>
#include <glpk.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

/* ok, this is cheating a bit ... */
#define GLP_SUCCESS 0

/*=====================================================================*
 *                                state                                *
 *=====================================================================*/

static uint64_t
make_ticket ()
{
  uint64_t ticket;
  struct timeval t;

  gettimeofday (&t, NULL);

  ticket = t.tv_sec;
  ticket *= 1000000;
  ticket += t.tv_usec;

  return ticket;
}

ssize_t read(int fd, void *buf, size_t count);

static ssize_t
complete_read (int    fd,
               void*  buf,
               size_t count)
{
  ssize_t total = 0;

  while (count > 0)
    {
      ssize_t rv = read (fd, buf, count);

      if (rv < 0)
        {
          if (errno != EINTR)
            {
              return rv;
            }
        }
      else
        {
          total += rv;
          count -= rv;
          buf = (char *) buf + rv;
        }
    }

  return total;
}

static ssize_t
complete_write (int         fd,
                const void* buf,
                size_t      count)
{
  ssize_t total = 0;

  while (count > 0)
    {
      ssize_t rv = write (fd, buf, count);

      if (rv < 0)
        {
          if (errno != EINTR)
            {
              return rv;
            }
        }
      else
        {
          total += rv;
          count -= rv;
        }
    }

  return total;
}

#include "deserialize.h"
#include "reply.h"
#include "handlers.c"

static DriverData*
driver_data_new (ErlDrvPort port)
{
  DriverData* d = driver_alloc (sizeof (DriverData));

  memset (d, 0, sizeof (*d));

  d->port = port;
  set_port_control_flags (port, PORT_CONTROL_FLAG_BINARY);

  d->prob = glp_create_prob ();
  glp_create_index (d->prob);

  pthread_attr_init (&d->attr);

  socketpair (AF_UNIX, SOCK_STREAM, 0, d->eventfd);
  driver_select (d->port, (ErlDrvEvent) (intptr_t) d->eventfd[0], DO_READ, 1);

  return d;
}

static void
driver_data_free (DriverData* d)
{
  if (d->solving)
    {
      // this blocks the main emulator thread, so
      // hopefully this never happens

      pthread_cancel (d->thread);
      pthread_join (d->thread, NULL);
    }

  driver_select (d->port, (ErlDrvEvent) (intptr_t) d->eventfd[0], DO_READ, 0);

  close (d->eventfd[1]);
  close (d->eventfd[0]);

  glp_delete_index (d->prob);
  glp_delete_prob (d->prob);

  driver_free (d);
}

/*=====================================================================*
 *                         Erl Driver callbacks                        *
 *=====================================================================*/

static int
init (void)
{
  return 0;
}

static ErlDrvData
start    (ErlDrvPort     port,
          char*          buf)
{
  (void) buf;

  return (ErlDrvData) driver_data_new (port);
}

static void
stop      (ErlDrvData      handle)
{
  driver_data_free ((DriverData*) handle);
}

/*=====================================================================*
 *                             Entry Point                             *
 *=====================================================================*/

static ErlDrvEntry driver_entry = 
{
  .init = init,
  .start = start, 
  .stop = stop,
  .control = control,
  .ready_input = ready_input,
  .driver_name = (char*) "libglpkerldrv",
  .extended_marker = ERL_DRV_EXTENDED_MARKER,
  .major_version = ERL_DRV_EXTENDED_MAJOR_VERSION,
  .minor_version = ERL_DRV_EXTENDED_MINOR_VERSION,
  .driver_flags = ERL_DRV_FLAG_USE_PORT_LOCKING
};

DRIVER_INIT (libglpkerldrv);

DRIVER_INIT (libglpkerldrv) /* must match name in driver_entry */
{
  return &driver_entry;
}
