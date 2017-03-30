#include "genBST.h"

void genBST(int n, int *values){
    int** bst = allocate2D(n, 2);
    assert(bst != NULL);
    print_BST(n, bst);
    desallocate2D(bst);
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

void print_BST_line(int n, int **bst){
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("[%d,%d]", bst[i][0], bst[i][1]);
    }
    printf("]\n");
}
