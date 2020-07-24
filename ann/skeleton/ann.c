#include "ann.h"

/* Creates and returns a new ann. */
ann_t *ann_create(int num_layers, int *layer_outputs)
{
  /**** PART 2 - QUESTION 1 ****/
  return NULL; // delete after implementing
  /* 4 MARKS */
}

/* Frees the space allocated to ann. */
void ann_free(ann_t *ann)
{
  /**** PART 2 - QUESTION 2 ****/

  /* 2 MARKS */
}

/* Forward run of given ann with inputs. */
void ann_predict(ann_t const *ann, double const *inputs)
{
  /**** PART 2 - QUESTION 3 ****/

  /* 2 MARKS */
}

/* Trains the ann with single backprop update. */
void ann_train(ann_t const *ann, double const *inputs, double const *targets, double l_rate)
{
  /* Sanity checks. */
  assert(ann != NULL);
  assert(inputs != NULL);
  assert(targets != NULL);
  assert(l_rate > 0);

  /* Run forward pass. */
  ann_predict(ann, inputs);

  /**** PART 2 - QUESTION 4 ****/

  /* 3 MARKS */
}
