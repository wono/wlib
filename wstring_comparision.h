/* * * * * * * * * * * * * * * * * * * * * * * *        
 *  WSTRING_COMPARISON_H
 *                                                                  *
 *      last modified:  2014/05/28                                  *
 *      first wrote:    2014/05/28                                  *
 *                                                                  *
 *      wono (a.k.a wonho)                                          *
 *                                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

#ifndef _WSTRING_COMPARISION_H_
#define _WSTRING_COMPARISION_H_

/*  returns 1 two strings are equal, otherwise returns 0     */
static inline int IS_EQUAL_STRING ( char * s1, char * s2 )
{
    for (; *s1 == *s2; *s1++, *s2++)
        if (*s1 == '\0' && *s2 == '\0') return 1;
        
    return 0;
}

#endif
