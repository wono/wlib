/*  a simple & safe funtion to get value from input stream
 *
 *      last modified:  2014/08/22
 *      first wrote:    2014/04/24
 *
 *      Wonho Lim
 */

#ifndef _winput_handler_h_
#define _winput_handler_h_

#include "wassert.h"

static const size_t DEFAULT_MAX_LENGTH_INTEGER     = 8;
static const size_t DEFAULT_MAX_LENGTH_STRING      = 32;

/*  input_stream can be either stdin or a file pointer
 *  WASSERT () is defined in wassert.h  */
inline static int GET_INTEGER_FROM (void *input_stream)
{
    int i = 0;
    char bfr[DEFAULT_MAX_LENGTH_INTEGER];
    
    WASSERT (fgets (bfr, DEFAULT_MAX_LENGTH_INTEGER, input_stream));
    WASSERT (1 == sscanf (bfr, "%d", &i));
    
    return i;
}

/*  input_stream can be either stdin or a file pointer
 *  WASSERT () is defined in wassert.h  */
inline static char *GET_STRING_FROM (void *input_stream)
{
    char *bfr   = malloc (DEFAULT_MAX_LENGTH_STRING);
    char *s     = NULL;
    
    WASSERT (bfr);
    WASSERT (fgets (bfr, DEFAULT_MAX_LENGTH_STRING, input_stream));

    s = bfr;    free (bfr);
    
    return s;
}

#endif
