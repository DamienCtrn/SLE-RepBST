#ifndef __GENBST_H__
#define __GENBST_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

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
 * Function basically printing the BST
 * @param n number of values
 * @param bst tree [[-1,-1],[0,2],[-1,-1]]
 */
void print_BST_line(int n, int **bst);

#endif // __GENBST_H__
