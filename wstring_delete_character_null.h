/*  WSTRING_DELETE_CHARACTER_NULL
 *
 *      last modified:  2014/08/22
 *      first wrote:    2014/05/06
 *
 *      Wonho Lim
 */
 
#ifndef _wstring_delete_character_null_h_
#define _wstring_delete_character_null_h_

#include "wmemory_allocation.h"
#include "wstring/wstring_length.h"

static inline char * DELETE_CHARACTER_NULL ( char * string )
{
    size_t  i       = 0;
    size_t  length  = WSTRING_LENGTH  ( string );
    char *  result  = ALLOCATE_MEMORY ( length );

    while (0 != string[i])
        result[i++] = string[i];
    
    RETURN_AND_RELEASE ( result );
}

#endif
