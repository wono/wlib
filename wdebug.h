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

/*  << modifications by wono >>
 *
 *  date:     2014/03/11
 *  1.  cut out long lines by concatenating
 *  2.  uncapitalized lables 
 *      ex) [INFO] --> [info]
 *  3.  new format - aligned file name and line numbers
 *      ex) [info] (main.c:41)
 *          [info] (main.c:9)
 *      --> [info: main.c, 41]
 *          [info: main.c,  9]
 */

/*  << ver. 1.0.1 : 2014/03/18 >>
 *  re-aligned code - enhanced formats.
 */
