#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node_tag{
  struct node_tag *next;
  void *data;
} node;

typedef struct linkedList_tag{
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  node *head;
  node *tail;
} linkedList;

void list_init(linkedList *list, void (*destroy)(void *data));
void list_destroy(linkedList *list);
int list_ins_next(linkedList *list, node *node, const void *data);
int list_rm_next(linkedList *list, node *node, void **data);
void list_display(linkedList *list);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
