#include "logical.h"

void logical_operator_use(char x)
{
    printf("\n");
    for (int i = 0; i < 15; i++)
    {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (x == 'A')
            {
                printf("%d AND %d = %d\n", i, j, i && j);
            }
            else if (x == 'O')
            {
                printf("%d OR %d = %d\n", i, j, i || j);
            }
            else if (x == 'X')
            {
                printf("%d XOR %d = %d\n", i, j, i ^ j);
            }
        }
    }
}