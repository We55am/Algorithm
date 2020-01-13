#ifndef QUEUE_H
#define QUEUE_H

#include "../ADT_linked-list/linked-list.h"
#include <stdlib.h>

typedef linkedList Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *queue, void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_size list_size
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data) 

#endif
