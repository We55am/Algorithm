#ifndef __SORT__H
#define __SORT__H

#include <stdlib.h>
#include <string.h>

#include "list.h"

/* the compare function should return :
   1  if  key1 > key2
   0  if  key1 <= key2
*/

void insertionSort(List *list, int (*compare)(const void *key1, const void *key2));
void quickSort(List *list, int (*compare)(const void *key1, const void *key2));

int def_compare_int(const void *key1, const void *key2);

#endif
