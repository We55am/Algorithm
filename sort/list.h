#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node_tag{
  struct node_tag *next;
  void *data;
} node;

typedef struct List_tag{
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  node *head;
  node *tail;  
}List;


void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, node *node, const void *data);
int list_rm_next(List *list, node *node, void **data);
void list_display(List *list);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
