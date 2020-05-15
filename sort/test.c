#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "list.h"
#include "sort.h"

int main(void) {
  List mylist;
  list_init(&mylist, free);
  unsigned int data1 = 10;
  unsigned int data2 = 5;
  unsigned int data3 = 6;
  unsigned int data4 = 1;
  unsigned int data5 = 7;
  unsigned int data6 = 0;
  unsigned int data7 = 12;
  list_append(&mylist, &data1);
  list_append(&mylist, &data2);
  list_append(&mylist, &data3);
  list_append(&mylist, &data4);
  list_append(&mylist, &data5);
  list_append(&mylist, &data6);
  list_append(&mylist, &data7);
  printf("before insertion sort: \n");
  list_display(&mylist);
  printf("After insertion sort: \n");
  insertionSort(&mylist, def_compare_int);
  list_display(&mylist);
    
  return EXIT_SUCCESS;
}
