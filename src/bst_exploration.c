#include "bst_exploration.h"

/**
 * Fill the Exploring Structure
 * with the average cost of each sub-tree possible and their roots
 * @return average cost (also in cost_array[nb_values][0])
 */
int explore_and_store(Explo_Arrays *e, inttype *values){
    int n = e->nb_values;
    int c, sum;
    // Sub-array of just 1 element is the element
    for (size_t i = 0; i < n; i++) {
        e->cost_array[0][i] = values[i];
        e->root_array[0][i] = i;
    }
    // For each sub-array length possible (already done l=1)
    for (size_t l = 2; l <= n; l++) {
        // For each beginning index possible
        for (size_t k = 0; k < n-l+1; k++) {
            // Try as root all the indexes between k and k+l
            sum = part_array_sum(values, k, l);
            for (size_t i = k; i < k+l; i++) {
                c = sum + ((i >   k  )? e->cost_array[ i-k-1 ][ k ] : 0)
                        + ((i < k+l-1)? e->cost_array[k+l-i-2][i+1] : 0);
                if (c < e->cost_array[l-1][k]) {
                    e->cost_array[l-1][k] = c;
                    e->root_array[l-1][k] = i;
                }
            }
        }
    }
    return e->cost_array[n-1][0];
}

/**
 * Recurcive filling of the array tree of BST structure
 * Using the root_array of the Explo_Arrays structure
 * @param n : total length of the initial value array
 * @param L : length of the tree array
 * @param b : index of beginning
 * @return  : root of the sub-tree
 */
int fill_BST(int **tree, int n, short **root_array, int L, int b){
    if (L < 1 || L > n || b < 0 || b > n-L) {
        return -1;
    } else {
        int r = root_array[L-1][b];
        tree[r][0] = fill_BST(tree, n, root_array,     r-b, b);
        tree[r][1] = fill_BST(tree, n, root_array, b+L-r-1, r+1);
        return r;
    }
}

/**
 * Initializing an exploration array structure
 */
void initialize_EA(Explo_Arrays *e, int n){
    // Allocation
    e->cost_array = allocateEA_inttype(n);
    assert(e->cost_array != NULL);
    e->root_array = allocateEA_short(n);
    assert(e->root_array != NULL);
    // Initialization
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n-i; j++) {
            e->cost_array[i][j] = MAX_TYPE;
            e->root_array[i][j] = -1;
        }
    }
    e->nb_values = n;
}

/**
 * Function allocating memory for a specific data structure
 * the type allocated is defined by inttype
 * the data array is contiguous
 */
inttype ** allocateEA_inttype(int n){
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
 * Function allocating memory for a specific data structure
 * the data array is contiguous
 */
short ** allocateEA_short(int n){
    short **p = NULL;

    // Allocation the adresses of lines
    p = (short **)calloc(n, sizeof(*p));
    if (p == NULL) {
        return NULL;
    }
    else {
        // Allocating the data array
        *p = (short *)calloc((n * (n + 1))/2, sizeof(**p));
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
            printf(" %lu ", e->cost_array[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("[");
        for (size_t j = 0; j < n-i; j++) {
            printf(" %hi ", e->root_array[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    printf("===================================================================\n");
}

/**
 * Sums the values of an array from begin to begin + length (not included)
 */
inttype part_array_sum(inttype *array, int begin, int length){
    inttype s = 0;
    for (size_t i = begin; i < begin + length; i++) {
        s += array[i];
    }
    return s;
}
