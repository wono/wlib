/*  WSTRING_CONCAT
 *
 *      last modified:  2014/05/06
 *      first wrote:    2014/05/06
 *
 *      wono (a.k.a wonho)
 */
 
#ifndef _wstring_concat_h_
#define _wstring_concat_h_

#include <wmemory/wmemory_allocation.h>
#include <wstring/wstring_length.h>

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
    //RETURN_AND_RELEASE (string_new);
    free (string_new);
    return string_new;
}

#endif
