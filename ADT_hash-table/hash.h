#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include "../ADT_linked-list/linked-list.h"

typedef struct CHTbl_tag {
  int buckets;
  int (*h)(const void *key);
  int (*match)(const void *key1, const void *key2);
  int (*destroy)(void *data);
  int size;
  linkedList *table;
} CHTbl;

int chbtl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl, const void *data);
int chtbl_remove(CHTbl *htbl, void **data);
int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif
