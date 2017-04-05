#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define STACK_MAX_SIZE 1000


typedef struct stack {
    int data[STACK_MAX_SIZE];
    int size;
} Stack;

/**
 * Initialization of the Stack s
 */
void stack_init(Stack *s);

/**
 * Printing the Stack
 * Stoping at the actual size
 */
void stack_print(Stack *s);

/**
 * Poping the front element
 * Returning it and decrementing the size field
 * @return -1 if the stack is empty
 */
int stack_pop(Stack *s);

/**
 * Pushing one element
 * @return -1 if the stack is full
 */
int stack_push(Stack *s, int d);

/**
 * Viewing the top element
 * @return -1 if the stack is empty
 */
int stack_top(Stack *s);

#endif /* end of include guard: __STACK_H__ */
