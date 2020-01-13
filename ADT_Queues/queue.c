#include "queue.h"
#include <stdlib.h>

int queue_enqueue(Queue *queue, void *data) {
  return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue, void **data) {
  return list_rm_next(queue, NULL, data);
}

