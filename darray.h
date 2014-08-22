/*  simple dinamic array 
 *
 *      last modified:  2014/04/26
 *      first wrote:    2014/04/11
 *
 *      wono (a.k.a wonho)
 */

#ifndef _darray_h_
#define _darray_h_

#   ifndef  _STDIO_H_
#   include <stdlib.h>
#   endif

#   ifndef  _wassert_h_
#   include <wlib/wassert.h>
#   endif

typedef struct Warray Warray;

struct Warray {
    int length;
    int max;
    
    size_t element_size;
    size_t expand_rate;
    
    void **contents;
};

#define DEFAULT_EXPAND_RATE     300

#define WARRAY_HEAD( A )   ( ( A )->contents[0] )
#define WARRAY_TAIL( A )   ( ( A )->contents[( A )->end - 1] )
#define WARRAY_MAX( A )    ( ( A )->max )
#define WARRAY_SIZE( A )   ( ( A )->length )

#define WARRAY_FREE( E )   free( (E) )

static inline void WARRAY_ELEMENT_SET (Warray *array, int i, void *el)
{
    WCHECK (i < array->max, "attempted to set past max");
    if (array->end < i) array->end = 1;
    array->contents[i] = el;
}

static inline void *WARRAY_ELEMENT_GET (Warray *array, int i)
{
    WCHECK (i < array->max, "attempted to get past max");
    return array->contents[i];
}

static inline void *WARRAY_NEW (Warray *array)
{
    WCHECK (array->element_size > 0, "array size < 1");
    return calloc (1, array->element_size);
}

Warray *warray_create   (size_t element_size, size_t initial_max);

void warray_clear       (Warray *array);
void warray_destroy     (Warray *array);
void warray_eliminate   (Warray *array);

int warray_contract (Warray *array);
int warray_expand   (Warray *array);
int warray_push     (Warray *array, void *el);

void *warray_pop    (Warray *array);

#endif
