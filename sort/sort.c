#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sort.h"
#include "list.h"


static void ins_sort(List **list, node **head, node *new_node, int (*compare)(const void *key1, const void *key2));
static node *partition(node *head, node *end, node **newHead, node **newEnd, int (*compare)(const void *key1, const void *key2));
static node *quickSortRecur(node *head, node *end, int (*compare)(const void *key1, const void *key2));
static node *getTail(node *cur);

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

void quickSort(List *list, int (*compare)(const void *key1, const void *key2)) {
  list_head(list) = quickSortRecur(list_head(list), list_tail(list), compare);
  list_tail(list) = getTail(list_head(list));
}

static node *quickSortRecur(node *head, node *end, int (*compare)(const void *key1, const void *key2))
{
  
    if (!head || head == end) 
        return head; 
  
    node *newHead = NULL, *newEnd = NULL; 
  
    node *pivot = partition(head, end, &newHead, &newEnd, compare); 
   
    if (newHead != pivot) 
    { 
        node *tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = NULL;
	
        newHead = quickSortRecur(newHead, tmp, compare);
	
        tmp = getTail(newHead); 
        tmp->next = pivot; 
    }
    
    pivot->next = quickSortRecur(pivot->next, newEnd, compare); 
  
    return newHead; 
}

static node *partition(node *head, node *end, node **newHead, node **newEnd, int (*compare)(const void *key1, const void *key2)) {
  node *pivot = end;
  node *prev = NULL;
  node *tail = pivot;
  node *current = head;
  while(current != pivot)
    {
      if (compare(pivot->data, current->data))
	{
	  if ((*newHead) == NULL)
	    (*newHead) = current;
	  prev = current;
	  current = current->next;
	}
      else
	{
	  if (prev)
	    prev->next = current->next;
	  node *temp = current->next;
	  current->next = NULL;
	  tail->next = current;
	  tail = current;
	  current = temp;
	}
    }

  if ((*newHead) == NULL)
    (*newHead) = pivot;
  (*newEnd) = tail;

  return pivot;
  
}
int def_compare_int(const void *key1, const void *key2) {
  if ((*(int*)(key1)) > (*(int*)(key2)))
    {
      return 1;
    }
  return 0;
}

static node *getTail(node *cur) 
{
  while (cur != NULL && cur->next != NULL)
    cur = cur->next;
  return cur; 
} 
