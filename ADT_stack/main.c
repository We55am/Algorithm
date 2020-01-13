#include "stack.h"
#include "../ADT_linked-list/linked-list.h"
#include <stdio.h>

int main(void) {
  Stack stack;
  int x = 5;
  void *ptr = &x;
  void *ptrptr = &ptr;
  stack_init(&stack, free);
  stack_push(&stack, ptr);
  stack_push(&stack, ptr);
  stack_push(&stack, ptr);
  stack_push(&stack, ptr);
  list_display(&stack);
  printf("pop value is: %d and x now is: %d\n", stack_pop(&stack, ptrptr), x);
  list_display(&stack);
  return 0;
}
