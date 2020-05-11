#include "func.h"

int main(int argc, char **argv)
{
    float a = 0.0, b = 0.0;

    if (argc < 3)
    {
        puts("\nPlease give two floating point numbers, separated by a space:");
        scanf("%f %f", &a, &b);
    }
    else
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
    }
    printf("\nGiven input:\n a == %f\n b == %f\n", a, b);
    exchange(&a, &b);
    printf("\nAfter an exchange the values are as follows:\n a == %f\n b == %f\n", a, b);
}