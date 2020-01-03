#include "node.h"

void insert_tail(node_t * head, int val) { // insert at the end of the list.
  node_t * current = head;
  while (current->next != NULL){
    current = current->next;
  }
  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->value = val;
  current->next->next = NULL;
}

void insert_head(node_t ** head, int val) { // insert at the beginning of the List.
  node_t * new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node->next = *head;
  new_node->value = val;
  *head = new_node;
}

void insert_indx(node_t * head, int val, int indx) { // insert at indx
  if (indx == 0) insert_head(&head, val);
  else {
    node_t * current = head;
    int cunt = 0;
    while ((*current).next != NULL) {
      cunt++;
      if (cunt == indx) {
	node_t * new_node = (node_t *) malloc(sizeof(node_t));
	new_node->value = val;
	new_node->next = current->next;
	current->next = new_node;
	break;
      }
      current = current->next;
    }
  }
}

bool isempty(node_t * head) { // Check if empty
  if (head == NULL) return true;
  else return false;
}

int remove_tail(node_t * head) { // Remove the last item.
  int result = 0;
  // If list is empty;
  if (isempty(head)) {
    return -1;
  }
  // If the List have only 1 node
  if (head->next == NULL) {
    result = head->value;
    free(head);
    return result;
  }

  node_t * current = head;
  while(current->next->next != NULL) {
    current = current->next;
  }

  result = current->next->value;
  free(current->next);
  current->next = NULL;
  return result;
}

int remove_head(node_t ** head) { // Removing the first item and return it.
  int result = 0;
  
  if (isempty(*head)) {
    return -1;
  }

  node_t * next_node = (*head)->next;
  result = (*head)->value;
  free(*head);
  *head = next_node;
  return result;
}

int remove_indx(node_t * head, int indx) { // remove and return index
  if (indx == 0) return remove_head(&head);
  else {
    int result = 0;
    int cunt = 0;
    node_t * current = head;
    while (current->next != NULL) {
      cunt++;
      if (cunt == indx) {
	result = current->next->value;
	free(current->next);
	current->next = current->next->next;
      }
      current = current->next;
    }
    return result;
  }
}

int get_indx(node_t * head, int indx){ // get (without removing) index's value
  node_t * current = head;
  if (indx == 0) return head->value;
  int cunt = 0;
  
  while (current->next != NULL) {
    cunt++;
    if (cunt == indx) {
      return current->next->value;
    }
    current = current->next;
  }

  return -1;
}

int get_head(node_t * head) {
  if (!(isempty(head))) return head->value;
  return -1;
}

int get_tail(node_t * head) {
  node_t * current = head;
  if (isempty(head)) return -1;
  while(current->next != NULL) {
    current = current->next;
  }
  return current->value;
}

void display_list(node_t * head) { // Display the List.
  node_t * current = head;
  printf("Displaying the LinkedList:\n");
  while (current != NULL) {
    printf("[%d]->",current->value);
    current = current->next;
  }
  printf("NULL\n");
}
