/*  WMALLOC.H
 *
 *      last modified:  2014/08/22
 *      first wrote:    2014/05/05
 *
 *      Wonho Lim
 */

#ifndef _wmalloc_h_
#define _wmalloc_h_

#include <stdlib.h>
#include "wassert.h"

static inline void * MEMORY_ALLOCATE ( size_t  size )
{
    void *ptr = malloc ( size );
    WASSERT ( ptr );
    return  ( ptr );
}         

static inline void MEMORY_RELEASE ( void * p )
{
    if (p)  free (p);    
}

#endif
