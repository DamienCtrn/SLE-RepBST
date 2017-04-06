#ifndef __GENBST_H__
#define __GENBST_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "binary_search_tree.h"
#include "stack.h"

#define INFINITE 1000000
#define TAB_STACK_SIZE 10

/**
 * Main function calling the calculus function
 * @param n number of values
 * @param values array of values
 */
void genBST(int n, int *values);

/**
 * Basic implementation of Bellman's equation
 * !! Do not gathers and stocks the index in a 2D array !!
 * Examining all the possibilities
 * @param values array of element
 * @param n number of elements
 * @param depth actual depth of the tree
 * @param i_ret root chosen
 * @return average cost of accessing to an element
 */
int recurciv_gen1(int *values, int n, int depth, int *i_ret);

#endif /* end of include guard: __GENBST_H__ */
