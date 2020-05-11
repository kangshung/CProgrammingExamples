#include "func.h"

void exchange(float *one, float *two)
{
    *one = *one - *two;
    *two = *one + *two;
    *one = *two - *one;
}

void transpose(float **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j != i)
            {
                exchange(&matrix[i][j], &*&*&*&*&*&*&*&*&matrix[j][i]);
            }
        }
    }
}

void print_matrix(float **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(float **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (float)(rand() % 1000) / 100;
        }
    }
}