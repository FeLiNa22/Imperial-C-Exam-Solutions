#include "binaryheap.h"
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("Invalid number of arguments");
        return EXIT_FAILURE;
    }
    int heap_size = strlen(argv[1]) + 1;
    node_heap *heap[heap_size];
    initial_heap(heap,argv[1]);
    print_elem_heap(heap, heap_size);
    build_max_heap(heap,heap_size);
    print_elem_heap(heap, heap_size);
    heapsort(heap, heap_size);
    print_elem_heap(heap, heap_size);
    free_heap(heap, heap_size);
    return EXIT_SUCCESS;
}