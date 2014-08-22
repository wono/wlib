/*  WSTRING_DELETE_CHARACTER
 *      : within a string, deletes any character but null
 *
 *      last modified:  2014/08/22
 *      first wrote:    2014/05/01
 *
 *      Wonho Lim
 */

#ifndef _wstring_delete_character_h_
#define _wstring_delete_character_h_

#include <stdlib.h>
#include "wstring_length.h"

inline static char *
WSTRING_DELETE_CHARACTER (  char *      string,
                            const char  character   )
{
    size_t  i       = 0;
    size_t  j       = 0;
    size_t  length  = WSTRING_LENGTH_GET (string);
    char *  result  = malloc (length);
    
    for (; 0 != string[i]; ++i) {
        if (character != string[i]) {
            result[j++] = string[i];
         }
    } result[j] = 0;
    
    free (result);
    return result;
}

#endif
