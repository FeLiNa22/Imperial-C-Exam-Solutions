#ifndef _REGIONS_H_
#define _REGIONS_H_

#include "image.h"
#include "typedefs.h"
#include <stdint.h>
#include <stdio.h>

/////ALL THESE FUNCTIONS ARE PROVIDED FOR YOU/////////////////////
/////DO NOT MODIFY THEM///////////////////////////////////////////

// Our colour function of choice
uint8_t region_colour(const region_t *region);


// Resets a point to (x,y)
void init_point(point_t *point, int x, int y);


// Resets an extent to (width, height)
void init_extent(extent_t *extent, int width, int height);

// Allocates a region. You may assume that the return value is non-NULL.
region_t *region_allocate(void);


// Prints a textual description of a region to the supplied FILE*.
void print_region(FILE *out, const region_t *region);


// Finds all regions located in "image" and adds them to "regions".
// Regions are added so that ordering according to the
// comparison function region_compare() is preserved.
void find_regions(list_t *regions, image_t *image);
////////////////////////////////////////////////////////////////////

/////////////////////////USEFUL FUNCTIONS///////////////////////////
/////////////////////////////////////////////////////////////////////

// Compares two points lexicographically.
// Returns 1 if first is less than second, otherwise 0.
// Ordering of comparison is [y, x].
//
// You are NOT required to implement this function. However you may find
// it helpful to do so for Part I, Q1.
int point_compare_less(const point_t *first, const point_t *second);

// Deallocates a region.
// You are NOT required to implement this function. However, you may
// find it helpful to do so for Part I, Q3.
void region_destroy(region_t *region);

////////////////TO BE IMPLEMENTED///////////////////////////////////
///////////////////////////////////////////////////////////////////

// Compares two regions.
// Returns 1 if position of first is lexicographically less than that
// of the second, otherwise returns 0.
int region_compare(const region_t *first, const region_t *second);

// Prints all regions in "regions" to "out".
// print_region (above) prints a textual description of a region to
// the supplied FILE*
void print_regions(FILE *out, list_t *regions);



// Fills the specified region in the image with the pixel value "value".
void image_fill_region(image_t *image, const region_t *region, uint8_t value);

// Determines the extent of a region.
// position: the location of the top-left-hand corner of the region.
// image: the image to be searched.
// extent: this will be populated with the width and height of a region.
void find_extent(extent_t *extent, image_t *image, const point_t *position);

// Finds all regions located in the region "current" of "image" and adds them
// to "regions".  Regions are added so that ordering according to the
// comparison function region_compare() is preserved.
void find_sub_regions(list_t *regions, image_t *image,
                      const region_t *current);

// Renders all regions to an image using colour_function_t
//(declared in region.h) to select pixel intensity.
void render_regions(image_t *image, list_t *regions,
                    colour_function_t get_colour);
//////////////////////////////////////////////////////////////////////////////
#endif
