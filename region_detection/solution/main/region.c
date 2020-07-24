#include "region.h"
#include "image.h"
#include "typedefs.h"
#include "list.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/////ALL THESE FUNCTIONS ARE PROVIDED FOR YOU/////////////////////
/////DO NOT MODIFY THEM///////////////////////////////////////////

// Our colour function of choice
uint8_t region_colour(const region_t *region) {
    const unsigned depth = region->depth;
    return (depth * 1879u) % 255;
}

// Resets a point to (x,y)
void init_point(point_t *point, int x, int y) {
    point->x = x;
    point->y = y;
}

// Resets an extent to (width, height)
void init_extent(extent_t *extent, int width, int height) {
    extent->width = width;
    extent->height = height;
}


// Allocates a region. You may assume that the return value is non-NULL.
region_t *region_allocate(void) {
    region_t *new_region = malloc(sizeof(region_t));

    if (new_region == NULL) {
        perror("region_allocate");
        exit(EXIT_FAILURE);
    }

    return new_region;
}

// Prints a textual description of a region to the supplied FILE*.
void print_region(FILE *out, const region_t *region) {
    assert(out != NULL);
    assert(region != NULL);

    fprintf(out, "Region of depth %i at (%i, %i) of extent (%i, %i)\n",
            region->depth, region->position.x, region->position.y,
            region->extent.width, region->extent.height);
}

// Finds all regions located in "image" and adds them to "regions".
// Regions are added so that ordering according to the
// comparison function region_compare() is preserved.
void find_regions(list_t *regions, image_t *image) {
    region_t *image_region = region_allocate();

    image_region->depth = 0;
    init_point(&image_region->position, 0, 0);
    init_extent(&image_region->extent, image->width, image->height);

    list_insert_ascending(regions, image_region);
    find_sub_regions(regions, image, image_region);
}

///////////////////////////////////////////////////////////////////

/////////////////////////USEFUL FUNCTIONS///////////////////////////
///////////////////////////////////////////////////////////////////

// Compares two points lexicographically.
// Returns 1 if first is less than second, otherwise 0.
// Ordering of comparison is [y, x].
//
// You are NOT required to implement this function. However you may find
// it helpful to do so for Part I, Q1.
int point_compare_less(const point_t *first, const point_t *second) {
    //TODO (optional)
    return 0;
}

// Deallocates a region.
//
// You are NOT required to implement this function. However, you may
// find it helpful to do so for Part I, Q3.
void region_destroy(region_t *region) {
    free(region);
}
///////////////////////////////////////////////////////////////////

////////////////TO BE IMPLEMENTED///////////////////////////////////
////////////////////////////////////////////////////////////////////


// Compares two regions.
// Returns 1 if position of first is lexicographically less than that
// of the second, otherwise returns 0.
// Ordering of the position comparison is [y, x].
int region_compare(const region_t *r1, const region_t *r2) {
    return (r1->position.y < r2->position.y || (r1->position.y == r2->position.y && r1->position.x < r2->position.x));
}


// Prints all regions in "regions" to "out".
// print_region (above) prints a textual description of a region
// to the supplied FILE*
void print_regions(FILE *out, list_t *regions) {
    list_elem_t *curr = regions->header->next;
    while (curr != regions->footer) {
        print_region(out, curr->region);
        curr = curr->next;
    }
}

//
// Sets the specified region of image "image" to the intensity value "value".
//
void image_fill_region(image_t *image, const region_t *region, uint8_t value) {
    for (int i = region->position.x; i < region->position.x + region->extent.width; ++i) {
        for (int j = region->position.y; j < region->position.y + region->extent.height; ++j) {
            set_pixel(image, i, j, value);
        }
    }
}

// Determines the extent of a region.
// position: the location of the top-left-hand corner of the region.
// image: the image to be searched.
// extent: this will be populated with the width and height of a region.
void find_extent(extent_t *extent, image_t *image, const point_t *position) {
    uint8_t initPixel = get_pixel(image, position->x, position->y);
    int region_width = 0, region_height = 0;
    // gets the new region width
    for (int x = position->x; x < position->x + extent->width && region_width == 0; ++x) {
        if (initPixel != get_pixel(image, x, position->y)) {
            region_width = x - position->x;
        }
    }
    // gets the new region height
    for (int y = position->y; y < position->y + extent->height && region_height == 0; ++y) {
        if (initPixel != get_pixel(image, position->x, y)) {
            region_height = y - position->y;
        }
    }
    init_extent(extent, region_width, region_height);
}

// Finds all regions located in the region "current" of "image" and adds them
// to "regions".  Regions are added so that ordering according to the
// comparison function region_compare() is preserved.

void find_sub_regions(list_t *regions, image_t *image, const region_t *current) {
    //TODO
    uint8_t background = get_pixel(image, current->position.x, current->position.y);
    for (int j = current->position.y; j < current->position.y + current->extent.height; ++j) {
        for (int i = current->position.x; i < current->position.x + current->extent.width; ++i) {
            if (get_pixel(image, i, j) != background) {
                region_t *image_region = region_allocate(); // creates new region
                image_region->depth = current->depth + 1; // depth is incremented

                init_point(&image_region->position, i, j); // point is setup
                find_extent(&image_region->extent, image, &image_region->position); // extent of region found

                list_insert_ascending(regions, image_region); // insert region into list

                find_sub_regions(regions, image, image_region); // recurse through sub -regions

                image_fill_region(image, image_region, background); // clear region once done with it
                // as regions do not overlap, we can go to nxt spot after
                // unnecessary but speeds it up
            }
        }
    }
}

// Renders all regions to an image using the supplied colour_function_t
// (declared in typedefs.h) to select pixel intensity.
void render_regions(image_t *image, list_t *regions,
                    colour_function_t get_colour) {
    list_elem_t *curr = regions->header->next;
    while (curr != regions->footer) {
        image_fill_region(image, curr->region, get_colour(curr->region));
        curr = curr->next;
    }
}
///////////////////////////////////////////////////////////////////////////////
