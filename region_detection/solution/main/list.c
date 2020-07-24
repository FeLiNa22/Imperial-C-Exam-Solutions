#include "list.h"
#include "region.h"
#include "typedefs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

/////ALL THESE FUNCTIONS ARE PROVIDED FOR YOU/////////////////////
/////DO NOT MODIFY THEM///////////////////////////////////////////

//allocates memory in the heap for a list_elem_t
static list_elem_t *alloc_list_elem() {
    list_elem_t *elem = malloc(sizeof(list_elem_t));

    if (elem == NULL) {
        perror("alloc_list_elem");
        exit(EXIT_FAILURE);
    }

    return elem;
}

// Initialises the list_t so it can be used with other list functions.
void list_init(list_t *list) {
    list->header = alloc_list_elem();
    list->footer = alloc_list_elem();
    list->header->next = list->footer;
    list->footer->prev = list->header;
    list->header->prev = NULL;
    list->footer->next = NULL;
}

// Return an iterator to the start of the list.
list_iter list_begin(list_t *list) {
    return list->header->next;
}

// Return an iterator to the end of the list.
//
// Note that this iterator points to an element "beyond" the final element of
// the list. This makes it possible to use it to insert an element at
//the end of the list.
// It should never have list_iter_value() called on it.
list_iter list_end(list_t *list) {
    return list->footer;
}

// Returns an iterator to the element following "iter".
list_iter list_iter_next(list_iter iter) {
    return iter->next;
}


// Returns an iterator to the element previous to "iter".
list_iter list_iter_prev(list_iter iter) {
    return iter->prev;
}

// Given an iterator, returns a pointer to the region associated
// with that iterator.
region_t *list_iter_value(list_iter iter) {
    return iter->region;
}


// Applies the supplied function "f" to every element in the list.
void list_apply_function(list_t *list, region_function_t f) {
    for (list_iter iter = list_begin(list);
         iter != list_end(list);
         iter = list_iter_next(iter)) {
        f(list_iter_value(iter));
    }
}

////////////////////////////////////////////////////////////////////

////////////////TO BE IMPLEMENTED///////////////////////////////////
///////////////////////////////////////////////////////////////////

// Inserts "region" into "list" before the element pointed to by "iter".
void list_insert(list_iter iter, region_t *region) {
    list_elem_t *listElem = alloc_list_elem();
    listElem->region = region;
    iter->prev->next = listElem;
    listElem->prev = iter->prev;
    listElem->next = iter;
    iter->prev = listElem;
}


// Inserts "region" into "list" using the ordering defined by the function
// region_compare().
void list_insert_ascending(list_t *list, region_t *region) {
    list_elem_t *curr = list->header->next;
    // Base Case
    while (curr != list->footer) {
        if (region_compare(region, curr->region)) {
            list_insert(curr, region);
            return;
        }
        curr=curr->next;
    }
    list_insert(curr, region);
}

// Reclaims all memory used by the list_t data structure including any
// contained region_t elements.
void list_destroy(list_t *list) {
    list_elem_t *curr = list->header->next;

    while(curr != list->footer){
        list_elem_t *temp = curr->next;
        region_destroy(curr->region);
        free(curr);
        curr = temp;
    }
    free(list->header);
    free(list->footer);
}
///////////////////////////////////////////////////////////////////////
