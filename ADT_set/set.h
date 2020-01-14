#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "../ADT_linked-list/linked-list.h"

typedef linkedList Set;

#define set_destroy list_destroy

void set_init(Set *set, int (*match)(const void *arg1, const void *arg2), void (*destroy)(void *arg));
int set_insert(Set *set, const void *data);
int set_remove(Set *set, void **data);
int set_union(Set *setu, const Set *set1, const Set *set2);
int set_intersection(Set *seti, const Set *set1, const Set *set2);
int set_difference(Set *setd, const Set *set1, const Set *set2);
int set_is_member(const Set *set, const void *data);
int set_is_subset(const Set *set1, const Set *set2);
int set_is_equal(const Set *set1, const Set *set2);
int set_size(const Set *set);

#define set_size(set) ((set)->size)

#endif
