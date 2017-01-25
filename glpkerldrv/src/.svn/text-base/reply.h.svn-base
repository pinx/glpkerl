#ifndef __REPLY_H__
#define __REPLY_H__

static int
reply_prefixed_binary (char**      rbuf,
                       const void* prefix,
                       size_t      prefix_len,
                       const void* data,
                       size_t      len)
{
  ErlDrvBinary* bin = driver_alloc_binary (prefix_len + len);

  memcpy (bin->orig_bytes, prefix, prefix_len);
  memcpy (bin->orig_bytes + prefix_len, data, len);
  bin->orig_size = prefix_len + len;

  *rbuf = (char *) bin;

  return prefix_len + len;
}

static int
reply_error (char**      rbuf,
             const char* msg)
{
  return reply_prefixed_binary (rbuf, "\001", 1, msg, strlen (msg));
}

static int
reply_int32_t (char**    rbuf,
               int32_t   res)
{
  return reply_prefixed_binary (rbuf, "\000", 1, &res, 4);
}

static int
reply_uint64_t (char**    rbuf,
                uint64_t  res)
{
  return reply_prefixed_binary (rbuf, "\000", 1, &res, 8);
}

static int
reply_void (char** rbuf)
{
  *rbuf = NULL;

  return 0;
}

static int
reply_const_char_ptr (char**      rbuf,
                      const char* ptr)
{
  if (ptr == NULL)
    {
      return reply_prefixed_binary (rbuf, "\000", 1, NULL, 0);
    }
  else
    {
      return reply_prefixed_binary (rbuf, "\000", 1, ptr, strlen (ptr));
    }
}

static int
reply_double (char**    rbuf,
              double    res)
{
  return reply_prefixed_binary (rbuf, "\000", 1, &res, sizeof (res));
}

#endif /* __REPLY_H__ */
