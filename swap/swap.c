#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int swap(void *x, void *y, int size) {
  void *tmp;
  if ((tmp = malloc(size)) == NULL) return -1;
  memcpy(tmp, x, size);
  memcpy(x, y, size);
  memcpy(y, tmp, size);
  return 0;
}

int main(void) {
  char s1[] = "Hello";
  char s2[] = "World";
  printf("Before: %s %s\n", s1, s2);
  swap(s1, s2, sizeof(s1));
  printf("After: %s %s\n", s1, s2);
  return 0;
}
