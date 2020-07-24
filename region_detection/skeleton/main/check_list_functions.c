#include "region.h"
#include "list.h"
#include "test_regions.h"
#include "typedefs.h"
#include <stdlib.h>
#include <memory.h>

/////ALL THESE FUNCTIONS ARE PROVIDED FOR YOU/////////////////////
/////DO NOT MODIFY THEM. JUST RUN THE PROGRAM/////////////////////

static void print_test_data(void)
{
  printf("The following sorted list of regions will be used for testing:\n");
  fflush(stdout);

  for(size_t i = 0; i < num_test_regions; ++i)
  {
    print_region(stdout, &test_regions[i]);
  }
  fflush(stdout);
}

static void print_and_free_regions(list_t *regions)
{
  printf("Printing using print_regions():\n\n");
  fflush(stdout);
  print_regions(stdout, regions);

  printf("Freeing data... ");
  fflush(stdout);
  list_destroy(regions);
  printf("done.\n");
  fflush(stdout);
}

static void print_unordered_insert(void)
{
  printf("\n\nInserting into list in arbitrary order using list_insert()... ");
  fflush(stdout);
  static const size_t reorder[] = {6, 1, 4, 3, 5, 0, 2};

  list_t region_list;
  list_init(&region_list);
  for(size_t i = 0; i < num_test_regions; ++i)
  {
    region_t *region = region_allocate();
    memcpy(region, &test_regions[reorder[i]], sizeof(region_t));
    list_insert(list_begin(&region_list), region);
  }

  fflush(stdout);
  printf("done.\n");
  fflush(stdout);

  print_and_free_regions(&region_list);
}

static void print_ordered_insert(void)
{
  printf("\n\nInserting into list in arbitrary order using "
         "list_insert_ascending()... ");
  fflush(stdout);
  static const size_t reorder[] = {1, 6, 4, 5, 3, 0, 2};

  list_t region_list;
  list_init(&region_list);
  for(size_t i = 0; i < num_test_regions; ++i)
  {
    region_t *region = region_allocate();
    memcpy(region, &test_regions[reorder[i]], sizeof(region_t));
    list_insert_ascending(&region_list, region);
  }

  fflush(stdout);
  printf("done.\n");
  fflush(stdout);

  print_and_free_regions(&region_list);
}


int main(void)
{
  print_test_data();
  print_unordered_insert();
  print_ordered_insert();
  return EXIT_SUCCESS;
}
///////////////////////////////////////////////////////////////////////////////
