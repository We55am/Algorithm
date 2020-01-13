#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


int main(void) {
  Queue q;
  int x = 100;
  void *ptr = &x;
  queue_init(&q, free);
  queue_enqueue(&q, ptr);
  queue_enqueue(&q, ptr);
  queue_enqueue(&q, ptr);
  queue_enqueue(&q, ptr);
  list_display(&q);
  return EXIT_SUCCESS;
}
