#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

node list_getindex(List *list, int indx)
{
  node *current = list_head(list);

  for(int i = 0; i < indx; i++)
  {
    current = current->next;
  }
  return (*current);
}

void list_init(List *list, void (*destroy)(void *data)) {
  list_size(list) = 0;
  list->destroy = destroy;
  list_head(list) = NULL;
  list_tail(list) = NULL;
  return;
}

void list_destroy(List *list) {
  void *data;
  while(list_size(list) > 0) {
    if (list_rm_next(list, NULL, (void **)&data) == 1 && list->destroy != NULL) {
      list -> destroy(data);
    }
  }
  memset(list, 0, sizeof(List));
  return;
}

int list_ins_next(List *list, node *node, const void *data) {
  struct node_tag *new_node;
  
  if ((new_node = (struct node_tag *)malloc(sizeof(struct node_tag))) == NULL)
    return -1;
  
  new_node->data = (void *)data;
  
  if (node == NULL) {
    if (list_size(list) == 0) 
      list_tail(list) = new_node;
    
    new_node->next = list_head(list);
    list_head(list) = new_node;
    
  }
  else {
    if (node->next == NULL)
      list->tail = new_node;
    
    new_node->next = node->next;
    node->next = new_node;
    
  }
  list_size(list)++;
  return 0;
}

int list_rm_next(List *list, node *node, void **data) {
  struct node_tag *old_node;

  if (list_size(list) == 0)
    return -1;

  if (node == NULL) {
    *data = list->head->data;
    old_node = list->head;
    list->head = list->head->next;

    if (list_size(list) == 1)
      list->tail = NULL;
	
  }
  else {
    if (node->next == NULL)
      return -1;
    *data = node->next->data;
    old_node = node->next;
    node->next = node->next->next;

    if (node->next == NULL)
      list->tail = node;
  }

  free(old_node);
  list->size--;
  return 0;
}

void list_display(List *list) {
  if (list_size(list) == 0) {
    printf("The list is Empty!\n");
    return;
  }
  printf("Linked List: ");
  struct node_tag *current = list->head;
  for (int i = 0; i < list_size(list); i++) {
    printf("[%d]->", (*(int *)(current->data)));
    current = current->next;
  }
  printf("NULL \n");
  return;
}

int list_append(List *list, const void *data) {
  if (list_ins_next(list, list_tail(list), data) == -1)
    return -1;
  else
    return 0;
}
