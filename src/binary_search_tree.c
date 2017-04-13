#include "binary_search_tree.h"

/**
 * Initializing a Tree with -1 values
 */
void initialize_BST(BST *tree, int n){
    // Allocation
    tree->bst = allocate2D(n, 2);
    assert(tree->bst != NULL);
    // Initialization
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 2; j++) {
            tree->bst[i][j] = -1;
        }
    }
    tree->nb_values = n;
    tree->root = -1;
    tree->avg_cost = MAX_TYPE;
}

/**
 * Function allocating memory for a 2D array
 * the data array is contiguous
 */
short ** allocate2D(int nb_lines, int nb_columns){
    short **p = NULL;

    // Allocation the adresses of lines
    p = (short **)calloc(nb_lines, sizeof(*p));
    if (p == NULL) {
        return NULL;
    }
    else {
        // Allocating the data array
        *p = (short *)calloc(nb_lines * nb_columns, sizeof(**p));
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
void desallocate2D(BST *tree){
    free(*tree->bst);
    free(tree->bst);
}

/**
 * Function printing the BST in command line
 */
void print_BST_line(BST *tree){
    printf("============- PRINTING BST -============\n");
    printf("  nb of elements = %d\n", tree->nb_values);
    printf("  root index     = %hi\n", tree->root);
    printf("  average cost   = %lld\n", tree->avg_cost);
    printf("[");
    for (size_t i = 0; i < tree->nb_values; i++) {
        // printf("[%hi,%hi]", tree->bst[i][0], tree->bst[i][1]);
    }
    printf("]\n");
    printf("========================================\n");
}

/**
 * Function printing the BST in C synthaxe
 */
void print_BST_Csynthax(BST *tree, inttype *values){
    printf("static long BSTdepth = %lld;\n", tree->avg_cost);
    printf("static int BSTroot = %hi;\n", tree->root);
    printf("static int BSTtree[%d][2] = {\n", tree->nb_values);
    for (size_t i = 0; i < tree->nb_values - 1; i++) {
        printf("{%hi, %hi}\n", tree->bst[i][0], tree->bst[i][1]);
    }
    printf("{%hi, %hi}};\n", tree->bst[tree->nb_values - 1][0],
                            tree->bst[tree->nb_values - 1][1]);
    printf("static int BSTfreq[%d] = {\n", tree->nb_values);
    for (size_t i = 0; i < tree->nb_values - 1; i++) {
        printf("%lld,\n", values[i]);
    }
    printf("%lld};\n", values[tree->nb_values - 1]);
}
