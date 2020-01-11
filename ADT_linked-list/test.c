#include <stdio.h>
#include <stdlib.h>

#include "linked-list.c"


int main(void) {
  linkedList list;
  list_init(&list, free);
  list_display(&list);
  int x = 66;
  int y = 100;
  int z = 150;
  const void *ptr = &x;
  const void *ptr2 = &y;
  const void *ptr3 = &z;
  list_ins_next(&list, NULL, ptr);
  list_ins_next(&list, NULL, ptr2);
  list_ins_next(&list, NULL, ptr3);
  printf("The size of the list is: %d\n", list_size(&list));
  list_display(&list);
  list_ins_next(&list, (&list)->head->next, ptr3);
  list_display(&list);
  return 0;
}
