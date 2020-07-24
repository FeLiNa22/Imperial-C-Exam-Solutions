#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_

#include <stdio.h>
#include <stdlib.h>

/////THESE TYPES ARE PROVIDED FOR YOU/////////////////////////////
/////DO NOT MODIFY THEM///////////////////////////////////////////

typedef struct node_heap_t node_heap;

struct node_heap_t{
 char *key;
 int position;
};
//////////////////////////////////////////////////////////////////
/*allocate memory in the heap for a node_heap type element*/
 node_heap *allocate_node_heap(void);

/*initialise the heap array elements*/
void initial_heap(node_heap **heap, char* sequence);

/*print every element of the heap array*/
void print_elem_heap(node_heap **heap, int length);

/* returns the index in the heap array where the parent is allocated for the index passed as argument*/
 int parent(int index);

/* returns the index in the heap array where the left child is allocated for the index passed as argument*/
 int left_child(int index);

/* returns the index in the heap array where the right child is allocated for the index passed as argument*/
 int right_child(int index);

/* exchange the values of node1 to node2*/ 
 void swap(node_heap *node1, node_heap *node2);

/*Moves down the value of the heap[current] so the subtree rooted at index "current" satisfies with the max-heap property*/ 
 void max_heapify(node_heap **heap, int current, int heap_size);

/*it orders the heap so the ordered heap satisfies the max-heap property*/
void build_max_heap(node_heap **heap, int heap_size);

/*starting from a max-heap ordered array, it moves the largest item from the heap and it into the array position left as the heap shrinks*/
void heapsort(node_heap **heap, int length);

/*free the memory allocated by a node_heap type element in the heap*/
 void free_node(node_heap *node);

/*free the memory allocated in the heap array*/
void free_heap(node_heap **heap, int length);

#endif
