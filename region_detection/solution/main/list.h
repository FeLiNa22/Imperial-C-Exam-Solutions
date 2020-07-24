#ifndef _LIST_H_
#define _LIST_H_

#include "region.h"
#include <stdio.h>

/////ALL THESE FUNCTIONS ARE PROVIDED FOR YOU/////////////////////
/////DO NOT MODIFY THEM///////////////////////////////////////////

// Initialises the list_t so it can be used with other list functions.
void list_init(list_t *list);


// Return an iterator to the start of the list.
list_iter list_begin(list_t *list);


// Return an iterator to the end of the list.
//
// Note that this iterator points to an element "beyond" the final element of
// the list. This makes it possible to use it to insert an element
// at the end of the list.
// It should never have list_iter_value() called on it.
list_iter list_end(list_t *list);


// Returns an iterator to the element following "iter".
list_iter list_iter_next(list_iter iter);


// Returns an iterator to the element previous to "iter".
list_iter list_iter_prev(list_iter iter);

// Given an iterator, returns a pointer to the region associated with
//that iterator. list_iter_value() can be used to fetch the
//corresponding region_t*.
struct region  *list_iter_value(list_iter iter);


// Applies the supplied function "f" to every element in the list.
void list_apply_function(list_t *list, region_function_t f);


///////////////////////////////////////////////////////////////////////////////
///////////TO BE IMPLEMENTED///////////////////////////////////////////////////

// Inserts "region" into "list" before the element pointed to by "iter".
void list_insert(list_iter iter, region_t *region);


// Inserts "region" into "list" using the ordering defined by the function
// region_compare().
void list_insert_ascending(list_t *list, region_t  *region);

// Reclaims all memory used by the list_t data structure. region_t*
// elements stored in the list are *not* reclaimed by this function.
void list_destroy(list_t *list);

///////////////////////////////////////////////////////////////////////////////

#endif
