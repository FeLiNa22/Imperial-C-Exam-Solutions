#ifndef DRAGON_H_
#define DRAGON_H_

#include <stdint.h>

#define LEVEL 6

typedef struct vector
{
    long dx;
    long dy;
} vector_t;

/* DO NOT MODIFY THE DECLARATION OF THESE FUNCTIONS*/
vector_t starting_direction(int );
void draw_greyscale(image_t *, long , long  );
void string_iteration(image_t *, const char *, int  );
void dragon(long , int );

#endif /* DRAGON_H_ */
