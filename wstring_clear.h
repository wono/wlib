/*  WSTRING_CLEAR:
 *      fills string with null character until first null character 
 *      occurs. it can also be used static char array.
 *
 *  precondition:
 *      the string must either have dynamically allocaded memory or
 *      be char type of array.
 *
 *  this function is originally designed to re-initialize temporary
 *      local static char array for the next usage. it can be 
 *      optimized if the topper level function is frequently called. 
 *      use this function with static char array variable istaed of 
 *      dynamic memory allocation or general array for the local
 *      variable if topper level function is frequently called. 
 * 
 *      last modified:  2014/05/13
 *      first wrote:    2014/05/13
 *
 *      wono (a.k.a wonho)
 */
 
#ifndef _wstring_clear_h_
#define _wstring_clear_h_

static inline void WSTRING_CLEAR (char *a)
{
    size_t  i = 0;
    while (a[i])
        a[i++] = 0;
}

#endif
