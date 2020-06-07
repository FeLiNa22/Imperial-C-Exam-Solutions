#include "layer.h"

/* The sigmoid function and derivative. */
/* 1 MARK */
double sigmoid(double x) {
    /**** PART 1 - QUESTION 1 ****/
    return 1 / (1 + exp(-x));
}

double sigmoidprime(double x) {
    return x * (1 - x);
}

/* Creates a single layer. */
/* 2 MARKS */
layer_t *layer_create(void) {
    /**** PART 1 - QUESTION 2 ****/
    layer_t *layer;
    if ((layer = malloc(sizeof(layer_t))) == NULL) {
        perror("Error allocating memory for layer");
        return NULL;
    }
    layer->num_inputs = 0;
    layer->num_outputs = 0;
    return layer;
}

/* Initialises the given layer. */
/* 4 MARKS */
bool layer_init(layer_t *layer, int num_outputs, layer_t *prev) {
    /**** PART 1 - QUESTION 3 ****/
    layer->prev = prev;
    layer->num_outputs = num_outputs;
    layer->outputs = calloc(num_outputs, sizeof(double));
    if (layer->outputs == NULL) {
        return true;
    }
    if (prev != NULL) {
        // if not the input layer
        layer->num_inputs = prev->num_outputs;
        layer->biases = calloc(num_outputs, sizeof(double));
        layer->deltas = calloc(num_outputs, sizeof(double));
        layer->weights = malloc(sizeof(double *) * layer->num_inputs);
        if (layer->biases == NULL || layer->deltas == NULL || layer->weights == NULL) {
            return true;
        }
        for (int i = 0; i < layer->num_inputs; ++i) {
            layer->weights[i] = malloc(sizeof(double) * num_outputs);
            if (layer->weights[i] == NULL) {
                return true;
            }
            for (int j = 0; j < layer->num_outputs; ++j) {
                layer->weights[i][j] = ANN_RANDOM();
            }
        }
    }
    return false;
}

/* Frees a given layer. */
/* 2 MARKS */
void layer_free(layer_t *layer) {
    /**** PART 1 - QUESTION 4 ****/
    free(layer->outputs);
    if (layer->prev != NULL) {
        free(layer->deltas);
        free(layer->biases);
        for (int i = 0; i < layer->num_inputs; ++i) {
            free(layer->weights[i]);
        }
        free(layer->weights);
    }
    free(layer);
}

/* Computes the outputs of the current layer. */
/* 3 MARKS */
void layer_compute_outputs(layer_t const *layer) {
    /**** PART 1 - QUESTION 5 ****/
    if (layer->prev != NULL) {
        for (int j = 0; j < layer->num_outputs; ++j) {
            double sum = 0;
            for (int i = 0; i < layer->num_inputs; ++i) {
                sum += layer->weights[i][j] * layer->prev->outputs[i];
            }
            layer->outputs[j] = sigmoid(layer->biases[j] + sum);
        }
    }
}

/* Computes the delta errors for this layer. */
/* 2 MARKS */
void layer_compute_deltas(layer_t const *layer) {
    /**** PART 1 - QUESTION 6 ****/
    if(layer->next != NULL) {
        layer_compute_deltas(layer->next);
        /* objective: compute layer->deltas */
        for (int i = 0; i < layer->next->num_inputs; ++i) {
            double sum = 0;
            for (int j = 0; j < layer->next->num_outputs; ++j) {
                sum += layer->next->weights[i][j] * layer->next->deltas[j];
            }
            layer->deltas[i] = sigmoidprime(layer->outputs[i]) * sum;
        }
    }
}

/* Updates weights and biases according to the delta errors given learning rate. */
/* 1 MARK */
void layer_update(layer_t const *layer, double l_rate) {
    /**** PART 1 - QUESTION 7 ****/
    /* objective: update layer->weights and layer->biases */
    for (int i = 0; i < layer->num_inputs; ++i) {
        for (int j = 0; j < layer->num_outputs; ++j) {
            layer->weights[i][j] += l_rate * layer->prev->outputs[i] * layer->deltas[j];
        }
    }
    for (int k = 0; k < layer->num_outputs; ++k) {
        layer->biases[k] += l_rate * layer->deltas[k];
    }
}


