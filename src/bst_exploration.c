#include "bst_exploration.h"

/**
 * Initializing an exploration array structure
 */
void initialize_EA(Explo_Arrays *e, int n){
    // Allocation
    e->cost_array = allocateEA(n);
    assert(e->cost_array != NULL);
    e->root_array = allocateEA(n);
    assert(e->root_array != NULL);
    // Initialization
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n-i; j++) {
            e->cost_array[i][j] = MAX_INT;
            e->root_array[i][j] = -1;
        }
    }
    e->nb_values = n;
}

/**
 * Function allocating memory for a specific data structure
 * the data array is contiguous
 */
inttype ** allocateEA(int n){
    inttype **p = NULL;

    // Allocation the adresses of lines
    p = (inttype **)calloc(n, sizeof(*p));
    if (p == NULL) {
        return NULL;
    }
    else {
        // Allocating the data array
        *p = (inttype *)calloc((n * (n + 1))/2, sizeof(**p));
        if (*p == NULL) {
            free(p);
            return NULL;
        }
        else {
            // Bonding the adress array to actual data adresses
            for (size_t i = 1; i < n; i++) {
                p[i] = p[i-1] + n - i + 1;
            }
        }
    }
    return p;
}

/**
 * Function freeing memory previously allocated
 * with allocateEA
 */
void desallocateEA(Explo_Arrays *e){
    free(*e->cost_array);
    free(e->cost_array);
    free(*e->root_array);
    free(e->root_array);
}

/**
 * Function printing the Exploration Arrays in command line
 */
void print_EA_line(Explo_Arrays *e){
    int n = e->nb_values;
    printf("==================- Printing Exploration Arrays -==================\n");
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("[");
        for (size_t j = 0; j < n-i; j++) {
            printf(" %d ", e->cost_array[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("[");
        for (size_t j = 0; j < n-i; j++) {
            printf(" %d ", e->root_array[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    printf("===================================================================\n");
}
