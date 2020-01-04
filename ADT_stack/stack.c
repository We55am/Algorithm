#include "stack.h"

int main(void) {
  stack_t * s = newStack(8);
  push(s, 5);
  push(s, 8);
  push(s, 2);
  display_stack(s);
  pop(s);
  pop(s);
  pop(s);
  printf("POP agine: %d\n", pop(s));
  display_stack(s);
  push(s, 100);
  display_stack(s);
  printf("Get Size: %d\n", getSize(s));
  return EXIT_SUCCESS;
}

stack_t * newStack(int maxSize) {
  stack_t * stack = (stack_t *) malloc(sizeof(stack_t));
  stack->topOfStack = -1;
  stack->theArray = (int *) malloc(sizeof(int) * maxSize);
  stack->size = maxSize;
  return stack;
}

bool isFull(stack_t * stack) {
  if (stack->size == stack->topOfStack+1) return true;
  else return false;
}

bool isEmpty(stack_t * stack) {
  if (stack->topOfStack == -1) return true;
  else return false;
}

int getSize(stack_t * stack) {
  return stack->topOfStack+1;
}

void push(stack_t * stack, int val) {
  if (isFull(stack)) {
    printf("Stack Overflow!\n");
    return;
  }
  stack->topOfStack++;
  stack->theArray[stack->topOfStack] = val;
}

int pop(stack_t * stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow!\n");
    return -1;
  }
  int result = stack->theArray[stack->topOfStack];
  stack->topOfStack--;
  return result;
}

void display_stack(stack_t * stack) {
  printf("The Stack: \n");
  stack_t * tmp = newStack(stack->size);
  while(!isEmpty(stack)) {
    int val = pop(stack);
    printf("[%d]\n", val);
    push(tmp, val);
  }
  while(!isEmpty(tmp)) {
    push(stack, pop(tmp));
  }
}
