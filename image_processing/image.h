#ifndef __IMAGE_H_
#define __IMAGE_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../sort/sort.h"

#define SIZE 3
#define SIGMA 1.0

typedef struct _image{
    int row;
    int col;
    int *data;
    void (*destroy)(void *data);
} Image;


void image_init(Image *img, int raw, int col, void (*destroy)(void *data));
void image_destory(Image *img);
void print_kernal(float kernal[SIZE][SIZE]);
float matrix_sum_float(float matrix[SIZE][SIZE], int size);
int matrix_sum_int(int matrix[SIZE][SIZE], int size);

void corss_correlation(int kernal[SIZE][SIZE], Image *img);

#define img_pixel(img, y, x) ()
#define _matrix(kernal, x, y) *(*(kernal+x)+y)
#define img_row(img) (img->row)
#define img_col(img) (img->col)
#endif // __IMAGE_H_
