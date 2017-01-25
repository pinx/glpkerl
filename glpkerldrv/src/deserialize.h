#ifndef __DESERIALIZE_H_
#define __DESERIALIZE_H_

#define deserialize_double(buf, buflen)                         \
  ({                                                            \
    double len;                                                 \
                                                                \
    if (buflen < (int) sizeof (double))                         \
      {                                                         \
        goto ERROR;                                             \
      }                                                         \
                                                                \
    memcpy (&len, buf, sizeof (double));                        \
    buf += sizeof (double);                                     \
    buflen -= sizeof (double);                                  \
                                                                \
    len;                                                        \
  })

#define deserialize_int32_t(buf, buflen)                        \
  ({                                                            \
    int32_t len;                                                \
                                                                \
    if (buflen < 4)                                             \
      {                                                         \
        goto ERROR;                                             \
      }                                                         \
                                                                \
    memcpy (&len, buf, 4);                                      \
    buf += 4;                                                   \
    buflen -= 4;                                                \
                                                                \
    len;                                                        \
  })

#define deserialize_uint8_t(buf, buflen)                        \
  ({                                                            \
    uint8_t len;                                                \
                                                                \
    if (buflen < 1)                                             \
      {                                                         \
        goto ERROR;                                             \
      }                                                         \
                                                                \
    memcpy (&len, buf, 1);                                      \
    buf += 1;                                                   \
    buflen -= 1;                                                \
                                                                \
    len;                                                        \
  })

#define deserialize_uint32_t(buf, buflen)                       \
  ({                                                            \
    uint32_t len;                                               \
                                                                \
    if (buflen < 4)                                             \
      {                                                         \
        goto ERROR;                                             \
      }                                                         \
                                                                \
    memcpy (&len, buf, 4);                                      \
    buf += 4;                                                   \
    buflen -= 4;                                                \
                                                                \
    len;                                                        \
  })

#define deserialize_ptr(type, buf, buflen)                      \
  ({                                                            \
    uint32_t len = deserialize_uint32_t(buf, buflen);           \
    type* ptr;                                                  \
                                                                \
    if (buflen < (int) (len * sizeof (type)))                   \
      {                                                         \
        goto ERROR;                                             \
      }                                                         \
                                                                \
    ptr = (void*) buf;                                          \
    buf += len * sizeof (type);                                 \
    buflen -= len * sizeof (type);                              \
    ptr;                                                        \
  })

#define deserialize_optional(type, buf, buflen, dflt, method)   \
  ({                                                            \
     uint8_t byte = deserialize_uint8_t (buf, buflen);          \
     type res = (dflt);                                         \
                                                                \
     if (byte)                                                  \
       {                                                        \
         res = (method);                                        \
       }                                                        \
                                                                \
     res;                                                       \
  })

#endif /* __DESERIALIZE_H_ */
