#include "func.h"

int main()
{
    srand(time(NULL));

    int size = 0;
    printf("Please give the dimension of the matrix:\n");
    while (1)
    {
        scanf("%d", &size);
        if (size >= 1 && size <= 10)
        {
            break;
        }
        else
        {
            printf("\nIncorrect value!\n");
        }
    }

    float **matrix = (float **)malloc(sizeof(float *) * size);
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (float *)malloc(sizeof(float) * size);
    }

    fill_matrix(matrix, size);
    printf("\nOriginal matrix:\n");
    print_matrix(matrix, size);

    transpose(matrix, size);

    printf("\nTransposed matrix:\n");
    print_matrix(matrix, size);

    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}