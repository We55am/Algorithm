#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void fun_test(int *x, int *y, int (*ptr)(int arg1, int arg2)) {
  const int r = ptr(*x,*y);
  *x = r;
  *y = r;
  return;
}

int sum(int x, int y) {
  return x + y;
}

int multip(int x, int y) {
  return x * y;
}

double powww(double x, double y) {
  double result = pow(x, y);
  return result;
}

int main(void){
  printf("Hello World!\n");
  printf("Value 8.0 ^ 3 = %lf\n", powww(8.0, 3));
  int (*ptr)(int arg1, int arg2); // Pointer to a Function test
  ptr = sum;
  int x = 5;
  int y = 6;
  fun_test(&x, &y, ptr);
  int result = ptr(x, y);
  printf("The result/x/y: %d %d %d\n", result, x, y);
  double (*ptr2)(double arg1, double arg2);
  ptr2 = pow;
  double result2 = ptr2((double)x, (double)y);
  printf("x is : %d and y is: %d, Thus, result will be: %lf\n", x, y, result2);
  return EXIT_SUCCESS;
}
