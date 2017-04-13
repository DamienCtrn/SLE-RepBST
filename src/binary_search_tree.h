#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include "bst_exploration.h"


typedef struct bst {
    int nb_values;
    short root;
    inttype avg_cost;
    short **bst;
} BST;

/**
 * Initializing a Tree with -1 values
 */
void initialize_BST(BST *tree, int n);

/**
 * Function allocating memory for a 2D array
 * the data array is contigous
 */
short ** allocate2D(int nb_lines, int nb_columns);

/**
 * Function freeing memory previously allocated
 * with allocate2D
 */
void desallocate2D(BST *tree);

/**
 * Function printing the BST in command line
 */
void print_BST_line(BST *tree);

/**
 * Function printing the BST in C synthaxe
 */
void print_BST_Csynthax(BST *tree, inttype *values);

#endif /* end of include guard: __BINARY_SEARCH_TREE_H__ */
