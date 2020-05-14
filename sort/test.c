#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "list.h"

int main(void) {
  List mylist;
  list_init(&mylist, free);
  unsigned int data1 = 10;
  if(list_ins_next(&mylist, NULL, &(data1)));
    printf("10 has been inserted successfuly");
  return EXIT_SUCCESS;
}
