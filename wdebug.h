#ifndef __debug_h
#define __debug_h

#   ifndef __errno_h
#   include <errno.h>
#   endif

#   ifndef __stdio_h
#   include <stdio.h>
#   endif

#   ifndef __string_h
#   include <string.h>
#   endif

#   ifdef   NDEBUG
#   define  debug(M, ...)
#   else
#   define  debug(M, ...) \
            fprintf (stderr, "[debug: %s,%3d]" M "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)
#   endif

#define check(A, M, ...)        if(!(A)) \
        { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_debug(A, M, ...)  if(!(A)) \
        { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "out of memory.")

#define clean_errno() (0 == errno ? "none" : strerror(errno)) 

#define log_err(M, ...)  \
        fprintf (stderr, \
        "[error: %s,%3d: errno: %4s] " M "\n", \
        __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) \
        fprintf (stderr, \
        "[info:  %s,%3d] " M "\n", \
        __FILE__, __LINE__, ##__VA_ARGS__)

#define log_warn(M, ...) \
        fprintf (stderr, \
        "[warn:  %s,%3d: errno: %4s] " M "\n", \
        __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define sentinel(M, ...) \
        { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
