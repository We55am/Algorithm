#ifndef __IMAGE_H_
#define __IMAGE_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../sort/sort.h"

#define SIZE 5
#define SIGMA 1.0

typedef struct _image{
    int row;
    int col;
    int *data;
} Image;

void print_kernal(float kernal[SIZE][SIZE]);

#define _matrix(kernal, x, y) *(*(kernal+x)+y)

#endif // __IMAGE_H_
