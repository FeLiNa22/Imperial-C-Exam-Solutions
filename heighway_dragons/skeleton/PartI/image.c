#include "image.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

//////////////////////////////////////////////////////////////
//DO NOT MODIFY ANYTHING FROM THIS FILE///////////////////////
//////////////////////////////////////////////////////////////

/*
 * A table of error messages relating to the error codes defined in
 * image_error_t.
 */
static const char *image_error_table[] =
  { "",
    "Error: could not open supplied file.",
    "Error: could not read image format from supplied file.",
    "Error: invalid image format found in supplied file.",
    "Error: insufficient memory to process supplied file.",
    "Error: supplied file does not contain valid image sizes.",
    "Error: supplied file contains an invalid depth.",
    "Error: could not read pixel data from supplied file.",
    "Error: could not write pixel data from supplied file."
  };

/*
 * Prints an error message that corresponds to the supplied error code.
 */
void image_print_error(image_error_t error)
{
  fprintf(stderr,"%s\n", image_error_table[error]);
}

/*
 * Frees the memory associated with a PPM/PBM image. It is safe to pass NULL to
 * this function.
 */
void image_free(image_t *image)
{
  if (image == NULL)
  {
    return;
  }

  if (image->pixelsData != NULL)
  {
    free(image->pixelsData);
  }

  free(image);
}

/*
 * Attempts to read a PGM/PPM/PBM image stored in P4,P5 OR P6 format from
 * the given file.
 * Returns IMG_OK on success or an appropriate error code on failure. The
 * parameter out will contain the loaded image if and only if the return value
 * is IMG_OK.
 */
image_error_t image_read(const char *filename, image_t **out)
{
  image_t *image;

  FILE *in;
  char buffer[BUFFER_SIZE], c;
  imageformat type;

  //Open the file for reading.
  in = fopen(filename, "rb");
  if (!in)
  {
    return IMG_OPEN_FAILURE;
  }

  //Read in the image format; P6 and P4 is currently the only format supported.
  if (fgets(buffer, BUFFER_SIZE, in) == NULL)
  {
    return IMG_MISSING_FORMAT;
  }

  if (buffer[0] != 'P' && ( buffer[1] != '4' || buffer[1] != '6'
    || buffer[1] == '5' ))
  {
    return IMG_INVALID_FORMAT;
  }

  /*
   * Allocate space for the image header.
   */
  image = malloc(sizeof(image_t));

  if (image == NULL)
  {
      return IMG_INSUFFICIENT_MEMORY;
  }

  if (buffer[1] == '4')
  {
    image->nChannels = 1;
    image->depth = 255;
    type = PBM_FORMAT;
  }
  else if (buffer[1] == '5')
  {
    image->nChannels = 1;
    image->depth = 255;
    type = PGM_FORMAT;
  }
  else
  {
    image->nChannels = 3;
    type = PPM_FORMAT;
  }

  c = fgetc(in);
  while (c == '#')
  {
    while (fgetc(in) != '\n') { }
    c = fgetc(in);
  }

  ungetc(c, in);

  //Read the image's size information.
  if (fscanf(in, "%d %d", &image->width, &image->height) != 2)
  {
    return IMG_INVALID_SIZE;
  }

  //Add the widthstep information to allow to move between array
  image->widthStep = image->nChannels * image->width;

  //Read and check the image's RGB component depth in PPM image.
  if(type == PPM_FORMAT)
  {
    if ((fscanf(in, "%d", &image->depth) != 1) || image->depth != DEPTH)
    {
      return IMG_INVALID_DEPTH;
    }
  }
  else if (type == PGM_FORMAT)
  {
    int max_grey;
    fscanf(in, "%d", &max_grey);
  }

  // Skip over any remaining cruft preceding the pixel data.
  while (fgetc(in) != '\n') { }

  // Allocate and read pixel data.
  image->pixelsData = malloc(image->width * image->height *
                             image->nChannels * sizeof(uint8_t));
  if (!image->pixelsData)
  {
    return IMG_INSUFFICIENT_MEMORY;
  }

  if (fread(image->pixelsData,
    image->nChannels * image->width * sizeof(uint8_t),
    image->height, in) != image->height)
  {
    image_free(image);
    return IMG_READ_FAILURE;
  }

  fclose(in);
  *out = image;
  return IMG_OK;
}

/*
 * Writes the supplied image to the given file. Returns IMG_OK on success, or
 * an appropriate error code on failure.
 */
image_error_t image_write(const char *filename, image_t *image,
                          imageformat type)
{
  FILE *out;

  // Open file for output.
  out = fopen(filename, "wb");
  if (!out)
  {
      return IMG_OPEN_FAILURE;
  }

  //Print the header.
  if(type == PPM_FORMAT)
  {
    fprintf(out, "P6\n");
    fprintf(out, "%d %d\n", image->width, image->height);
    fprintf(out, "%d\n", image->depth);
  }
  else if (type == PBM_FORMAT)
  {
    fprintf(out, "P4\n");
    fprintf(out, "%d %d\n", image->width, image->height);
  }
  else if (type == PGM_FORMAT)
  {
    fprintf(out, "P5\n");
    fprintf(out, "%d %d\n", image->width, image->height);
    fprintf(out, "%d\n", image->depth);
  }
  else
  {
    fclose(out);
    return IMG_INVALID_FORMAT;
  }

  //Print the pixel data.
  if (!fwrite(image->pixelsData, image->nChannels * image->width,
    image->height, out))
  {
    image_free(image);
    return IMG_WRITE_FAILURE;
  }

  fclose(out);
  return IMG_OK;
}

/*
 * creates an image with width and height size, nChannels and depth pixel value.
 * It is using the image_error_t enum types provided in image.h
 */
image_error_t init_image(image_t** dst, int width, int height, int nChannels,
                         int depth)
{
    image_t *image = NULL;
    image = malloc(sizeof(image_t));

    if (image == NULL)
    {
        return IMG_INSUFFICIENT_MEMORY;
    }

    image->nChannels = nChannels;
    image->depth = depth;
    image->width = width;
    image->height = height;
    image->widthStep = nChannels * width;
    image->pixelsData = calloc(image->widthStep * image->height,
                               sizeof(uint8_t));

    if (image->pixelsData == NULL)
    {
        return IMG_INSUFFICIENT_MEMORY;
    }

    *dst = image;
    return IMG_OK;
}
/*
 * Writes "value" to the pixel (x,y) of the image argument.
 */
void set_pixel(image_t *dst, int x, int y, uint8_t value)
{
  assert(dst != NULL);
  assert(x >= 0);
  assert(y >= 0);
  assert(x < dst->width);
  assert(y < dst->height);

  dst->pixelsData[y * dst->widthStep + x * dst->nChannels] = value;
}

/*
 * Reads the pixel intensity from location (x,y).
 */
uint8_t get_pixel(image_t *src, int x, int y)
{
  assert(src != NULL);
  assert(x >= 0);
  assert(y >= 0);
  assert(x < src->width);
  assert(y < src->height);

  return src->pixelsData[y * src->widthStep + x * src->nChannels];
}

//////////////////////////////////////////////////////////////



