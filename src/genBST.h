#ifndef __GENBST_H__
#define __GENBST_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

typedef struct bst {
    int nb_values;
    int root;
    int depth;
    int **bst;
} BST;

/**
 * Main function calling the calculus function
 * @param n number of values
 * @param values array of values
 */
void genBST(int n, int *values);

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
void print_BST_line(BST tree);

#endif // __GENBST_H__
