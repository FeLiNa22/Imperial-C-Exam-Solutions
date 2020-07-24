#include "ann.h"

/* Creates and trains a simple ann for XOR. */
int main()
{
  printf("Big data machine learning.\n\n");
  printf("--------------------------\n");

  /* Intializes random number generator */
  srand(42);

  /* Here is some BIG DATA to train, XOR function. */
  const double inputs[4][2] = {{0, 0},
                               {0, 1},
                               {1, 0},
                               {1, 1}};
  const double targets[] = {0, 1, 1, 0};

  printf("PART I - Creating a layer.\n\n");
  printf("Trying to layer_create.\n");
  layer_t *first_l = layer_create();
  if (!first_l) {
    printf("Couldn't create the first layer :(\n");
    return EXIT_FAILURE;
  }
  printf("Running layer_init.\n");
  if (layer_init(first_l, 2, NULL)) {
    printf("Couldn't layer_init first layer...\n");
    return EXIT_FAILURE;
  }
  printf("Here are some of the properties:\n");
  printf("  num_outputs: %i\n", first_l->num_outputs);
  printf("   num_inputs: %i\n", first_l->num_inputs);
  printf("   outputs[0]: %f\n", first_l->outputs[0]);
  printf("   outputs[1]: %f\n", first_l->outputs[1]);

  printf("\nCreating second layer.\n");
  layer_t *second_l = layer_create();
  if (!second_l) {
    printf("Couldn't create the second layer :(\n");
    return EXIT_FAILURE;
  }
  printf("Running layer_init on second layer.\n");
  if (layer_init(second_l, 1, first_l)) {
    printf("Couldn't layer_init second layer...\n");
    return EXIT_FAILURE;
  }
  printf("Here are some of the properties:\n");
  printf("  num_outputs: %i\n", second_l->num_outputs);
  printf("   num_inputs: %i\n", second_l->num_inputs);
  printf("   weights[0]: %f\n", second_l->weights[0][0]);
  printf("   weights[1]: %f\n", second_l->weights[1][0]);
  printf("    biases[0]: %f\n", second_l->biases[0]);
  printf("   outputs[0]: %f\n", second_l->outputs[0]);

  printf("\nComputing second layer outputs:\n");
  layer_compute_outputs(second_l);
  printf("Here is the new output:\n");
  printf("   outputs[0]: %f\n", second_l->outputs[0]);
  
  printf("\nFreeing both layers.\n");
  layer_free(second_l);
  layer_free(first_l);

  /* Create neural network. */
  printf("\n--------------------------\n");
  printf("PART II - Creating a neural network.\n");
  printf("2 inputs, 2 hidden neurons and 1 output.\n\n");
  printf(" * - * \\ \n");
  printf("         * - \n");
  printf(" * - * / \n\n");
  int layer_outputs[] = {2, 2, 1};
  ann_t *xor_ann = ann_create(3, layer_outputs);
  if (!xor_ann) {
    printf("Couldn't create the neural network :(\n");
    return EXIT_FAILURE;
  }

  /* Initialise weights to random. */
  printf("Initialising network with random weights...\n");

  /* Print hidden layer weights, biases and outputs. */
  printf("The current state of the hidden layer:\n");
  for(int i=0; i < layer_outputs[0]; ++i) {
    for(int j=0; j < layer_outputs[1]; ++j)
      printf("  weights[%i][%i]: %f\n", i, j, xor_ann->input_layer->next->weights[i][j]);
  }
  for(int i=0; i < layer_outputs[1]; ++i)
    printf("  biases[%i]: %f\n", i, xor_ann->input_layer->next->biases[i]);
  for(int i=0; i < layer_outputs[1]; ++i)
    printf("  outputs[%i]: %f\n", i, xor_ann->input_layer->next->outputs[i]);

  /* Dummy run to see random network output. */
  printf("Current random outputs of the network:\n");
  for(int i = 0; i < 4; ++i) {
    ann_predict(xor_ann, inputs[i]);
    printf("  [%1.f, %1.f] -> %f\n", inputs[i][0], inputs[i][1], xor_ann->output_layer->outputs[0]);
  }

  /* Train the network. */
  printf("\nTraining the network...\n");
  for(int i = 0; i < 25000; ++i) {
    /* This is an epoch, running through the entire data. */
    for(int j = 0; j < 4; ++j) {
      /* Training at batch size 1, ie updating weights after every data point. */
      ann_train(xor_ann, inputs[j], targets + j, 1.0);
    }
  }

  /* Print hidden layer weights, biases and outputs. */
  printf("The current state of the hidden layer:\n");
  for(int i=0; i < layer_outputs[0]; ++i) {
    for(int j=0; j < layer_outputs[1]; ++j)
      printf("  weights[%i][%i]: %f\n", i, j, xor_ann->input_layer->next->weights[i][j]);
  }
  for(int i=0; i < layer_outputs[1]; ++i)
    printf("  biases[%i]: %f\n", i, xor_ann->input_layer->next->biases[i]);
  for(int i=0; i < layer_outputs[1]; ++i)
    printf("  outputs[%i]: %f\n", i, xor_ann->input_layer->next->outputs[i]);

  /* Let's see the results. */
  printf("\nAfter training magic happened the outputs are:\n");
  for(int i = 0; i < 4; ++i) {
    ann_predict(xor_ann, inputs[i]);
    printf("  [%1.f, %1.f] -> %f\n", inputs[i][0], inputs[i][1], xor_ann->output_layer->outputs[0]);
  }

  /* Time to clean up. */
  ann_free(xor_ann);

  return EXIT_SUCCESS;
}
