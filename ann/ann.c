#include "ann.h"

/* Creates and returns a new ann. */
/* 4 MARKS */
ann_t *ann_create(int num_layers, int *layer_outputs) {
    /**** PART 2 - QUESTION 1 ****/
    if (num_layers < 2) {
        // must always have an input and output layer
        return NULL;
    }
    ann_t *ann;
    if ((ann = (ann_t *) malloc(sizeof(ann_t))) == NULL) {
        return NULL;
    }
    layer_t *prev, *curr;
    ann->input_layer = layer_create();
    if (ann->input_layer == NULL) {
        return NULL;
    }
    layer_init(ann->input_layer, layer_outputs[0], NULL);
    prev = ann->input_layer;
    for (int i = 1; i < num_layers; ++i) {
        curr = layer_create();
        if (curr == NULL) {
            return NULL;
        }
        layer_init(curr, layer_outputs[i], prev);
        prev->next = curr;
        prev = curr;
    }
    ann->output_layer = curr;
    ann->output_layer->next = NULL;
    return ann;
}

/* Frees the space allocated to ann. */
void ann_free(ann_t *ann) {
    /**** PART 2 - QUESTION 2 ****/
    layer_t *layer;
    layer = ann->input_layer;
    while (layer->next != NULL) {
        layer = layer->next;
        layer_free(layer->prev);
    }
    layer_free(ann->output_layer);
    free(ann);
    /* 2 MARKS */
}

/* Forward run of given ann with inputs. */
/* 2 MARKS */
void ann_predict(ann_t const *ann, double const *inputs) {
    /**** PART 2 - QUESTION 3 ****/
    for (int i = 0; i < ann->input_layer->num_outputs; ++i) {
        ann->input_layer->outputs[i] = inputs[i];
    }
    layer_t *layer;
    layer = ann->input_layer;
    while (layer->next != NULL) {
        layer_compute_outputs(layer);
        layer = layer->next;
    }
    layer_compute_outputs(ann->output_layer);
}

/* Trains the ann with single backprop update. */
/* 3 MARKS */
void ann_train(ann_t const *ann, double const *inputs, double const *targets, double l_rate) {
    /* Sanity checks. */
    assert(ann != NULL);
    assert(inputs != NULL);
    assert(targets != NULL);
    assert(l_rate > 0);

    /* Run forward pass. */
    ann_predict(ann, inputs);

    /**** PART 2 - QUESTION 4 ****/
    /* Run backward pass. */
    // compute deltas of output layer
    for (int j = 0; j < ann->output_layer->num_outputs; ++j) {
        ann->output_layer->deltas[j] =
                sigmoidprime(ann->output_layer->outputs[j]) * (targets[j] - ann->output_layer->outputs[j]);
    }
    // recursively compute layers of everything else
    layer_compute_deltas(ann->input_layer->next);
    layer_t *layer = ann->input_layer->next;
    while(layer->next != NULL){
        layer_update(layer,l_rate);
        layer = layer->next;
    }
    layer_update(layer,l_rate); //output layer
}
