#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

//////////////////////////////////////////////////////////////
//DO NOT MODIFY ANYTHING FROM THIS FILE///////////////////////
//////////////////////////////////////////////////////////////

// Struct defining a point in two-dimensional space
typedef struct point
{
  int x;
  int y;
} point_t;


// Struct defining the size of a two-dimensional region
typedef struct extent
{
  int width;
  int height;
} extent_t;


// Defines a region
typedef struct region
{
  point_t position;
  extent_t extent;
  int depth;
} region_t;


// The internal element type used by a list_t
typedef struct list_elem
{
  struct list_elem *prev;
  struct list_elem *next;
  struct region *region;
} list_elem_t;


// A list of regions
typedef struct list
{
  list_elem_t *header;
  list_elem_t *footer;
} list_t;

// Iterator type that can be used to iterate over the elements of a
//list_t in order.
typedef list_elem_t *list_iter;

// region_function_t is the type of a function pointer that takes a
// region_t* as a parameter.
typedef void (*region_function_t)(region_t *);

// A function that maps a region to an intensity value
typedef uint8_t (*colour_function_t)(const region_t *region);

#endif
