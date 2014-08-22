/*  WSTRING_TOUPPER_STRING
 *
 *      last modified:  2014/05/14
 *      first wrote:    2014/05/10
 *
 *      wono (a.k.a wonho)
 */

#ifndef _wstring_to_upper_h_
#define _wstring_to_upper_h_

#include <wascii/alphamap.h>

/*  precondition:
 *      the string must be dynamically allocated or defined as
 *      char array at the out of this function. allocate dynamic
 *      memory or define array at the toppest level where the variable
 *      is initiated as can as possible.
 *
 *  ASCII_TO_UPPER  ()      is defined in alphamap.h    */
static inline void 
WSTRING_TO_UPPER ( char * s )
{
    while (( *s++ = ASCII_TO_UPPER (*s) ));
}

#endif
