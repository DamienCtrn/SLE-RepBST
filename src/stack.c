#include "stack.h"

/**
 * Initialization of the Stack s
 */
void stack_init(Stack *s){
    s->size = 0;
}

/**
 * Printing the Stack from old to new
 * Stoping at the actual size
 */
void stack_print(Stack *s){
    printf("[");
    if (s->size != 0) {
        for (size_t i = 0; i < s->size - 1; i++) {
            printf("%d, ", s->data[i]);
        }
        printf("%d", s->data[s->size - 1]);
    }
    printf("]\n");
}

/**
 * Poping the front element
 * Returning it and decrementing the size field
 * @return -1 if the stack is empty
 */
int stack_pop(Stack *s){
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } else {
        return s->data[s->size-- - 1];
    }
}

/**
 * Pushing one element
 * @return -1 if the stack is full
 */
int stack_push(Stack *s, int d){
    if (s->size < STACK_MAX_SIZE){
        s->data[s->size++] = d;
        return 0;
    } else {
        fprintf(stderr, "Error: stack full\n");
        return -1;
    }
}

/**
 * Viewing the top element
 * @return -1 if the stack is empty
 */
int stack_top(Stack *s){
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } else {
        return s->data[s->size - 1];
    }
}
