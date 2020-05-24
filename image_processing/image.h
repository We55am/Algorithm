#ifndef __IMAGE_H_
#define __IMAGE_H_

typedef struct _image{
    int row;
    int col;
    int *data;
} Image;

#define _matrix(kernal, x, y) *(*(kernal+x)+y)

#endif // __IMAGE_H_
