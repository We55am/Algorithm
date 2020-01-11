#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

void stack_init(Stack *stack, void (*destroy)(void *data));
void stack_destroy(Stack *stack);
int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);
void *stack_peek(const Stack *stack);
int stack_size(const Stack *stack);


#endif
