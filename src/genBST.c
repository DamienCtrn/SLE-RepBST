#include "genBST.h"

/**
 * Main function calling the calculus function
 * @param n number of values
 * @param values array of values
 */
void genBST(int n, int *values){
    // BST Creation and Initialization
    BST tree;
    initialize(&tree, n);

    // Generating the tree
    tree.avg_cost = recurciv_gen1(values, n, 1, tree.bst, &tree.root);

    // Printing and Freeing
    print_BST_line(&tree);
    desallocate2D(tree.bst);
}

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
int recurciv_gen1(int *values, int n, int depth, int **tree, int *i_ret){
    // Limit cases
    if (n == 0) { *i_ret = -1; return 0; }
    if (n == 1) { *i_ret = 0;  return values[0]*depth; }

    // Normal cases
    int min = INFINITE;
    int curr;
    int i_left, i_right;
    for (size_t i = 0; i < n; i++) {
        curr = recurciv_gen1(values    , i    , depth+1, tree    , &i_left)
             + recurciv_gen1(values+i+1, n-1-i, depth+1, tree+i+1, &i_right)
             + values[i]*depth;
        if (curr < min) {
            min = curr;
            *i_ret = i;
            tree[i][0] = i_left;
            tree[i][1] = i_right + i + 1;
        }
    }
    return min;
}
