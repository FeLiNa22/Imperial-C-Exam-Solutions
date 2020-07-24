#ifndef IMAGE_H_
#define IMAGE_H_

#include <stdint.h>

//////////////////////////////////////////////////////////////
//DO NOT MODIFY ANYTHING FROM THIS FILE///////////////////////
//////////////////////////////////////////////////////////////

/*
 * The different type of image formats that loader accept
 */
typedef enum {PBM_FORMAT, PPM_FORMAT,PGM_FORMAT} imageformat;

/*
 * The maximum intensity of an RGB and GRAY value.
 */
enum {DEPTH = 255};

/*
 * number of channels in image
 */
enum {GRAY = 1, RGB = 3};

/*
 * The buffer size to be used by the PPM loader.
 */

enum {BUFFER_SIZE = 16};

/*
 * An image.
 */
typedef struct {
  int width, height;
  int nChannels;
  int widthStep;
  int depth;
  uint8_t *pixelsData;
} image_t;


/*
 * Image operation error codes.
 */
typedef enum{
  IMG_OK,
  IMG_OPEN_FAILURE,
  IMG_MISSING_FORMAT,
  IMG_INVALID_FORMAT,
  IMG_INSUFFICIENT_MEMORY,
  IMG_INVALID_SIZE,
  IMG_INVALID_DEPTH,
  IMG_READ_FAILURE,
  IMG_WRITE_FAILURE
} image_error_t;

/*
 * API prototypes.
 */

void image_print_error(image_error_t error_code);
void image_free(image_t *image);
image_error_t image_read(const char *filename, image_t **image_ptr);
image_error_t image_write(const char *filename, image_t *image,
                          imageformat format);
image_error_t init_image(image_t**, int, int, int, int);
void set_pixel(image_t *image, int x, int y, uint8_t colour);
uint8_t get_pixel(image_t *image, int x, int y);



#endif /* IMAGE_H_ */
