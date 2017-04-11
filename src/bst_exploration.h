#ifndef __BST_EXPLORATION_H__
#define __BST_EXPLORATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Definition of the int lenth used : 16 bits signed
#define MAX_TYPE 32767;
typedef short int inttype;


typedef struct explo_arrays {
    int nb_values;
    inttype **cost_array;
    inttype **root_array;
} Explo_Arrays;

/**************************************************************************
 *                        -= Structure description =-
 *
 *  [[ , , , ][ , , ][ , ][ ]] lines decrementing in length for each array
 *
 *         Allows to access to the cost and root of a sub-tree with :
 *                    ****_array[length-1][index of begin]
 *************************************************************************/

/**
 * Fill the Exploring Structure
 * with the average cost of each sub-tree possible and their roots
 * @return average cost (also in cost_array[nb_values-1][0])
 */
int explore_and_store(Explo_Arrays *e, int *values);

/**
 * Recurcive filling of the array tree of BST structure
 * Using the root_array of the Explo_Arrays structure
 * @param n : total length of the initial value array
 * @param L : length of the tree array
 * @param b : index of beginning
 * @return  : root of the sub-tree
 */
int fill_BST(int **tree, int n, inttype **root_array, int L, int b);

/**
 * Initializing an exploration array structure
 */
void initialize_EA(Explo_Arrays *e, int n);

/**
 * Function allocating memory for a specific data structure
 * the data array is contiguous
 */
inttype ** allocateEA(int n);

/**
 * Function freeing memory previously allocated
 * with allocateEA
 */
void desallocateEA(Explo_Arrays *e);

/**
 * Function printing the Exploration Arrays in command line
 */
void print_EA_line(Explo_Arrays *e);

/**
 * Sums the values of an array from begin to begin + length
 */
int part_array_sum(int *array, int begin, int length);

#endif /* end of include guard: __BST_EXPLORATION_H__ */
