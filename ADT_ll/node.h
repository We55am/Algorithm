#ifndef NODE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define NODE_H

struct node_tag {
  int value;
  struct node_tag * next;
};
typedef struct node_tag node_t;

void insert_tail(node_t * head, int val);
void insert_head(node_t ** head, int val);
void insert_indx(node_t * head, int val, int indx);
bool isempty(node_t * head);
int remove_tail(node_t * head);
int remove_head(node_t ** head);
int remove_indx(node_t * head, int indx);
int get_indx(node_t * head, int indx);
int get_head(node_t * head);
int get_tail(node_t * tail);
void display_list(node_t * head);
#endif
