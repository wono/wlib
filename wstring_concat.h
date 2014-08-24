/*  WSTRING_CONCAT
 *
 *      last modified:  2014/08/23
 *      first wrote:    2014/05/06
 *
 *      Wonho Lim
 */
 
#ifndef _wstring_concat_h_
#define _wstring_concat_h_

#include "wmemory_allocation.h"
#include "wstring_length.h"

static inline char *
WSTRING_CONCATENATE ( char * string1, char * string2 )
{
    size_t  i               = 0;
    size_t  j               = 0;
    
    size_t  length_str1     = WSTRING_LENGTH (string1);
    size_t  length_str2     = WSTRING_LENGTH (string2);
    size_t  length_total    = length_str1 + length_str2;
    
    char *  string_new      = ALLOCATE_MEMORY (length_total);
    
    while (0 != string1[i]) 
        string_new[i++] = string1[i];
    
    while ((string_new[i++] = string2[j++]));
    
    free (string_new);
    return string_new;
}

#endif
