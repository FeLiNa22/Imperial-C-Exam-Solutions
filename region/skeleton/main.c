#include "image.h"
#include "region.h"
#include "list.h"
#include "typedefs.h"
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////
//DO NOT MODIFY ANYTHING FROM THIS FILE///////////////////////
//////////////////////////////////////////////////////////////

static const char *pgm_output = "output.pgm";
static const char *txt_output = "regions.txt";

int main(int argc, char **argv)
{
  if (argc == 2)
  {

    // Load image
    const char *img_in_filename = argv[1];
    image_t *img_in = NULL;
    image_error_t img_err = image_read(img_in_filename, &img_in);
    if(img_err)
    {
      image_print_error(img_err);
      exit(EXIT_FAILURE);
    }

    // Initalise regions list
    list_t regions;
    list_init(&regions);

    // Identify and print regions
    find_regions(&regions, img_in);
    print_regions(stdout, &regions);

    // Write regions description to text file.
    FILE *text_out = fopen(txt_output,"w+");
    if (text_out == NULL)
    {
      perror("Text output file");
      exit(EXIT_FAILURE);
    }
    print_regions(text_out, &regions);
    fclose(text_out);


    // Allocate memory for output image
    image_t *img_out = NULL;
    img_err = init_image(&img_out, img_in->width, img_in->height, GRAY, 255);
    if(img_err)
    {
      image_print_error(img_err);
      exit(EXIT_FAILURE);
    }

    render_regions(img_out, &regions, region_colour);

    // Write output image to file
    img_err = image_write(pgm_output, img_out, PGM_FORMAT);
    if(img_err)
    {
       image_print_error(img_err);
       exit(EXIT_FAILURE);
    }

    // Deallocate memory for regions and region list.
    list_destroy(&regions);

    // Deallocate image data.
    image_free(img_in);
    image_free(img_out);
  }
  else
  {
    fprintf(stderr, "Usage: %s input_image\n", argv[0]);
    fprintf(stderr, "Textual description of regions will be written to %s"
            " and standard output.\n", txt_output);
    fprintf(stderr, "Re-rendered regions will be written to %s.\n", pgm_output);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

