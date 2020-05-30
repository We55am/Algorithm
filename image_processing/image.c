#include "image.h"

static int matrix_sum_int(float matrix[SIZE][SIZE], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result += matrix[i][j];
    return result;
}

static float matrix_sum_float(float matrix[SIZE][SIZE], int size)
{
    double result = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result += matrix[i][j];
    return result;
}



int main()
{
    
    float kernal[SIZE][SIZE];
    kernal[0][0] = 0.5;
    kernal[0][1] = 0.5;
    kernal[0][2] = 0.5;
    kernal[1][0] = 0.5;
    kernal[1][1] = 0.5;
    kernal[1][2] = 0.5;    
    kernal[2][0] = 0.5;
    kernal[2][1] = 0.5;
    kernal[2][2] = 0.5;

    float sum1 = matrix_sum_float(kernal, SIZE);
    int sum2 = matrix_sum_int(kernal, SIZE);
    //int med1 = matrix_median_int(kernal, SIZE);

    printf("sumfloat = %f, sumint = %d \n", sum1, sum2);


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
