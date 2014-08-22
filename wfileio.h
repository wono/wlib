/*
 *      last modified:  2014/08/22
 *      first wrote:    2014/04/18
 *
 *      wono (a.k.a wonho)
 */

#ifndef _wfileio_h_
#define _wfileio_h_

#include "wassert.h"

#define FOR_APPEND  "a+"
#define FOR_READ    "r+"
#define FOR_WRITE   "w+"

/*  F:  FILE pointer    */
#define RETURN_AFTER_CHECK( F )\
WASSERT ( F );\
return  ( F )

inline static FILE *
FILE_OPEN ( const char * file_path, 
            const char * open_option )
{
    FILE *pt = fopen (file_path, open_option);
    RETURN_AFTER_CHECK (pt);
}

inline static FILE_CLOSE (FILE *pt)
{
    WASSERT (0 == fclose(pt));
}

#endif
