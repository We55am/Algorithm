#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stack_tag {
  int topOfStack;
  int * theArray;
  int size;
} stack_t;

stack_t * newStack(int maxSize);
void push(stack_t * stack, int val);
int pop(stack_t * stack);
bool isempty(stack_t * stack);
bool isFull(stack_t * stack);
int getSize(stack_t * stack);
void display_stack(stack_t * stack);
#endif
