#ifndef __BST_EXPLORATION_H__
#define __BST_EXPLORATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Definition of the int lenth used : 16 bits signed
#define MAX_INT 32767;
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
 *                    ****_array[length][index of begin]
 *************************************************************************/


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

#endif /* end of include guard: __BST_EXPLORATION_H__ */
