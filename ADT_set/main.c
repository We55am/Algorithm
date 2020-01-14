#include <stdlib.h>
#include <stdio.h>
#include "../ADT_linked-list/linked-list.h"
#include "set.h"

int match_fun(const void *arg1, const void *arg2) {
  return arg1 == arg2;
}

int main(void) {
  Set set;
  int (*match)(const void *arg1, const void *arg2) = match_fun;
  set_init(&set, match, free);
  int d1 = 5;
  int d2 = 6;
  int d3 = 10;
  void *d1ptr = &d1;
  void *d2ptr = &d2;
  void *d3ptr = &d3;
  set_insert(&set, d1ptr);
  set_insert(&set, d2ptr);
  set_insert(&set, d3ptr);
  list_display(&set);
  set_insert(&set, d2ptr);
  return EXIT_SUCCESS;
}
