#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**** PART 3 - QUESTION 1 ****/
/* 4 MARKS */

/* Creates and displays random data for training. */
int main(int argc, char *argv[])
{
  /* Check argument count. */
  if (argc != 3) {
    printf("Usage, random_data rows columns\n");
    exit(EXIT_FAILURE);
  }

  /* Intializes random number generator */
  srand(time(NULL));

  /* Extract arguments. */
  int input_rows = atoi(argv[1]);
  int input_cols = atoi(argv[2]);

  /* Create dynamic arrays. */
  printf("Creating (%d, %d) -> %d input output combination.\n", input_rows, input_cols, input_rows);
  double **inputs = calloc(input_rows, sizeof(double*));
  double *targets = calloc(input_rows, sizeof(double));

  /* Initialise with random numbers. */
  for(int i = 0; i < input_rows; ++i) {
    inputs[i] = calloc(input_cols, sizeof(double));
    for(int j = 0; j < input_cols; ++j) {
      inputs[i][j] = (((double)rand())/RAND_MAX);
    }
    targets[i] = (((double)rand())/RAND_MAX);
  }

  /* Display the random data. */
  for(int i = 0; i < input_rows; ++i) {
    for(int j = 0; j < input_cols; ++j) {
      printf(" %f ", inputs[i][j]);
    }
    printf("-> %f\n", targets[i]);
  }

  /* Free up resources. */
  free(targets);
  free(inputs);

  return EXIT_SUCCESS;
}
