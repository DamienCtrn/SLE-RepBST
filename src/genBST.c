#include "genBST.h"

void genBST(int n, int *values){
    // BST Creation and Initialization
    BST tree;
    tree.bst = allocate2D(n, 2);
    assert(tree.bst != NULL);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 2; j++) {
            tree.bst[i][j] = -1;
        }
    }
    tree.nb_values = n;
    tree.depth = 0;
    tree.root =0;


    // Code to Add here ...


    // Printing and Freeing
    print_BST_line(tree);
    desallocate2D(tree.bst);
}

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

void desallocate2D(int **array){
    free(*array);
    free(array);
}

void print_BST_line(BST tree){
    printf("==== PRINTING BST ============\n");
    printf("  depth =          %d\n", tree.depth);
    printf("  nb of elements = %d\n", tree.nb_values);
    printf("  root index =     %d\n", tree.root);
    printf("[");
    for (size_t i = 0; i < tree.nb_values; i++) {
        printf("[%d,%d]", tree.bst[i][0], tree.bst[i][1]);
    }
    printf("]\n");
    printf("==============================\n");
}
