#include "layer.h"

/* The sigmoid function and derivative. */
double sigmoid(double x)
{
  /**** PART 1 - QUESTION 1 ****/
  return 42.0; // delete after implementing
  /* 1 MARK */
}

double sigmoidprime(double x)
{
  return x*(1 - x);
}

/* Creates a single layer. */
layer_t *layer_create()
{
  /**** PART 1 - QUESTION 2 ****/
  return NULL; // delete after implementing
  /* 2 MARKS */
}

/* Initialises the given layer. */
bool layer_init(layer_t *layer, int num_outputs, layer_t *prev)
{
  /**** PART 1 - QUESTION 3 ****/
  return true; // delete after implementing
  /* 4 MARKS */
}

/* Frees a given layer. */
void layer_free(layer_t *layer)
{
  /**** PART 1 - QUESTION 4 ****/

  /* 2 MARKS */
}

/* Computes the outputs of the current layer. */
void layer_compute_outputs(layer_t const *layer)
{
  /**** PART 1 - QUESTION 5 ****/
  /* objective: compute layer->outputs */

  /* 3 MARKS */
}

/* Computes the delta errors for this layer. */
void layer_compute_deltas(layer_t const *layer)
{
  /**** PART 1 - QUESTION 6 ****/
  /* objective: compute layer->deltas */

  /* 2 MARKS */
}

/* Updates weights and biases according to the delta errors given learning rate. */
void layer_update(layer_t const *layer, double l_rate)
{
  /**** PART 1 - QUESTION 7 ****/
  /* objective: update layer->weights and layer->biases */

  /* 1 MARK */
}
