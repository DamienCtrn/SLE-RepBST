#include "genBST.h"

/**
 * Main function calling the calculus function
 * @param n number of values
 * @param values array of values
 */
void genBST(int n, int *values){
    // BST Creation and Initialization
    BST tree;
    initialize_BST(&tree, n);

    // Generating the tree
    tree.avg_cost = recurciv_gen1(values, n, 1, &tree.root);

    // Testing stuff
    Explo_Arrays e;
    initialize_EA(&e, n);
    print_EA_line(&e);
    desallocateEA(&e);

    // Printing and Freeing
    print_BST_line(&tree);
    desallocate2D(&tree);
}

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
int recurciv_gen1(int *values, int n, int depth, int *i_ret){
    // Limit cases
    if (n == 0) { *i_ret = -1; return 0; }
    if (n == 1) { *i_ret = 0;  return values[0]*depth; }

    // Normal cases
    int min = INFINITE;
    int curr;
    int i_left, i_right;
    for (size_t i = 0; i < n; i++) {
        curr = recurciv_gen1(values    , i    , depth+1, &i_left)
             + recurciv_gen1(values+i+1, n-1-i, depth+1, &i_right)
             + values[i]*depth;
        if (curr < min) {
            min = curr;
            *i_ret = i;
        }
    }
    return min;
}
