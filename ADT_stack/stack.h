#ifndef stack_H
#define STACK_H

#include <stdlib.h>
#include <string.h>
#include "../ADT_linked-list/linked-list.h"

typedef linkedList Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? Null : (stack)->data)
#define stack_size list_size

#endif
