#ifndef __GENBST_H__
#define __GENBST_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#define INFINITE 1000000

typedef struct bst {
    int nb_values;
    int root;
    int avg_cost;
    int **bst;
} BST;

/**
 * Main function calling the calculus function
 * @param n number of values
 * @param values array of values
 */
void genBST(int n, int *values);

/**
 * Generating the Optimum tree recurcively
 * Examining all the possibilities
 * @param values array of element needed to be put in a tree
 * @param n number of elements
 * @param depth actual depth of the tree
 * @param tree binary search tree
 * @param i_ret root chosen
 * @return average cost of accessing to an element
 */
int recurciv_gen1(int *values, int n, int depth, int **tree, int *i_ret);

/**
 * Initializing a Tree with -1 values
 */
void initialize(BST *tree, int n);

/**
 * Function allocating memory for a 2D array
 * the data array is contigous
 */
int ** allocate2D(int nb_lines, int nb_columns);

/**
 * Function freeing memory previously allocated
 * with allocate2D
 */
void desallocate2D(int **array);

/**
 * Function printing the BST in command line
 */
void print_BST_line(BST *tree);

#endif // __GENBST_H__
