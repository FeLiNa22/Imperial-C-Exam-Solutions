#ifndef __ANN_H__
#define __ANN_H__

#include "layer.h"

/* Represents a N layer artificial neural network. */
typedef struct ann {
    /* The head and tail of layers doubly linked list. */
    layer_t *input_layer;
    layer_t *output_layer;
} ann_t;

/* Creates and returns a new ann. */
ann_t *ann_create(int num_layers, int *layer_outputs);
/* Frees the space allocated to ann. */
void ann_free(ann_t *ann);
/* Forward run of given ann with inputs. */
void ann_predict(ann_t const *ann, double const *inputs);
/* Trains the ann with single backprop update. */
void ann_train(ann_t const *ann, double const *inputs, double const *targets, double l_rate);

#endif
