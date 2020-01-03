#include "node.h"

int main(void) {
  node_t * head = (node_t *) malloc(sizeof(node_t));
  head->value = 10;
  insert_head(&head,1);
  insert_head(&head,2);
  insert_head(&head,5);
  insert_tail(head,9);
  insert_tail(head,12);
  display_list(head);
  remove_indx(head, 2);
  display_list(head);
  printf("The size of the list is: %d\n", getSize(head));
  return EXIT_SUCCESS;
}
