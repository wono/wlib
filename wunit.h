/*
 *      last modified:  2014/08/22
 *      first wrote:    2014/04/02
 *
 *      Wonho Lim
 */
 
#undef NDEBUG

#ifndef _wunit_test_h_
#define _wunit_test_h_

#   ifndef  _STDIO_H_
#   include <stdio.h>
#   endif

#   ifndef  _STDLIB_H_
#   include <stdlib.h>
#   endif

#   ifndef  _wassert_h_
#   include "wassert.h"
#   endif

#define _wu_suite_start() char *message = NULL

#define _wu_assert( test, message )\
if (!(test)) {log_err (message); return message;}

#define _wu_run_test( test )\
debug("\n-----%s", " " #test);\
message = test();\
tests_run++;\
if (message) return message;

#define _run_tests( name )\
int main (int argc, char *argv[]) {\
    argc = 1;\
    debug("----- RUNNING: %s", argv[0]);\
    char *result = name();\
    result \ 
        ? printf ("failed: %s\n", result)\
        : printf ("all tests are passed.\n");\
    printf ("tests run: %d\n", tests_run);\
    exit (0 != result);\
}

int tests_run;

#endif
