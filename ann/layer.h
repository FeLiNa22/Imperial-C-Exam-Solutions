#ifndef __LAYER_H__
#define __LAYER_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

/* Random number macro. */
#define ANN_RANDOM() (((double)rand())/RAND_MAX - 0.5)

/* The sigmoid function and derivative. */
double sigmoid(double x);
double sigmoidprime(double x);

/* Represents a single neural layer. */
typedef struct layer {
  /* Number of inputs and outputs (neurons).*/
  int num_inputs, num_outputs;
  /* Output of EACH neuron. */
  double *outputs;
  /* Pointers to previous and next layer if any. */
  struct layer *prev;
  struct layer *next;
  /* Incoming weights of EACH neuron. */
  double **weights;
  /* Biases of EACH neuron. */
  double *biases;
  /* Delta errors of EACH neuron. */
  double *deltas;
} layer_t;

/* Creates a single layer. */
layer_t *layer_create();
/* Initialises the given layer. */
bool layer_init(layer_t *layer, int num_outputs, layer_t *prev);
/* Frees a given layer. */
void layer_free(layer_t *layer);
/* Computes the outputs of the current and all subsequent layers given inputs. */
void layer_compute_outputs(layer_t const *layer);
/* Computes the delta errors for this layer and all previous layers (backpropagate). */
void layer_compute_deltas(layer_t const *layer);
/* Updates weights and biases according to the delta errors given learning rate. */
void layer_update(layer_t const *layer, double l_rate);

#endif
