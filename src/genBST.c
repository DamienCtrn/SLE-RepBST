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
    if (depth == 1) {
        recurciv_gen1(values, *i_ret, depth+1, tree, &i_left);
        recurciv_gen1(values+*i_ret+1, n-1-*i_ret, depth+1, tree+*i_ret+1, &i_right);
        tree[*i_ret][0] = i_left;
        tree[*i_ret][1] = i_right + *i_ret + 1;
    }
    return min;
}

/**
 * Initializing a Tree with -1 values
 */
void initialize(BST *tree, int n){
    tree->bst = allocate2D(n, 2);
    assert(tree->bst != NULL);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 2; j++) {
            tree->bst[i][j] = -1;
        }
    }
    tree->nb_values = n;
    tree->root = -1;
    tree->avg_cost = -1;
}

/**
 * Function allocating memory for a 2D array
 * the data array is contigous
 */
int ** allocate2D(int nb_lines, int nb_columns){
    int **p = NULL;

    // Allocation the adresses of lines
    p = (int **)calloc(nb_lines, sizeof(*p));
    if (p == NULL) {
        return NULL;
    }
    else {
        // Allocating the data array
        *p = (int *)calloc(nb_lines * nb_columns, sizeof(**p));
        if (*p == NULL) {
            free(p);
            return NULL;
        }
        else {
            // Bonding the adress array to actual data adresses
            for (size_t i = 1; i < nb_lines; i++) {
                p[i] = p[i-1] + nb_columns;
            }
        }
    }
    return p;
}

/**
 * Function freeing memory previously allocated
 * with allocate2D
 */
void desallocate2D(int **array){
    free(*array);
    free(array);
}

/**
 * Function printing the BST in command line
 */
void print_BST_line(BST *tree){
    printf("==== PRINTING BST ============\n");
    printf("  nb of elements = %d\n", tree->nb_values);
    printf("  root index     = %d\n", tree->root);
    printf("  average cost   = %d\n", tree->avg_cost);
    printf("[");
    for (size_t i = 0; i < tree->nb_values; i++) {
        printf("[%d,%d]", tree->bst[i][0], tree->bst[i][1]);
    }
    printf("]\n");
    printf("==============================\n");
}
