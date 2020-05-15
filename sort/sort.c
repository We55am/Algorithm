#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sort.h"
#include "list.h"

static void ins_sort(List **list, node **head, node *new_node, int (*compare)(const void *key1, const void *key2));

void insertionSort(List *list, int (*compare)(const void *key1, const void *key2)) {

  node *current = list_head(list);
  node *sorted = NULL;

  while (current != NULL)
    {
      node *next = current->next;
      ins_sort(&list, &sorted, current, compare);
      current = next;
    }

  list_head(list) = sorted;
}

static void ins_sort(List **list, node **head, node *new_node, int (*compare)(const void *key1, const void *key2)) {
  node *current;
  if (*head == NULL || compare(((*head)->data), new_node->data))
    {
      list_next(new_node) = *head;
      *head = new_node;
    }
  else
    {
      current = *head;
      while (current->next != NULL && compare(new_node->data, current->next->data))
	{
	  current = list_next(current);
	}
      if (current->next == NULL)
	(*list)->tail = new_node; 
      new_node->next = current->next;
      current->next = new_node;
    }
}


int def_compare_int(const void *key1, const void *key2) {
  if ((*(int*)(key1)) > (*(int*)(key2)))
    {
      return 1;
    }
  return 0;
}
