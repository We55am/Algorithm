#include "image.h"

#define SIZE 5
#define SIGMA 1.0

int main()
{
    
    float kernal[SIZE][SIZE];
    gauss_kernal(kernal, 1.0);

    kernal[1][3] = M_PI;
   // _matrix(kernal, 0, 0) = 0;
   // _matrix(kernal, 1, 1) = 1.5;
   // _matrix(kernal, 2, 2) = 43.5;

    print_kernal(kernal);

    return EXIT_SUCCESS;
}

void print_kernal(float kernal[SIZE][SIZE])
{
    printf("\nKernal .... :\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%f ", kernal[j][i]);
        }
        printf("\n");
    }
}
