#include "func.h"

void exchange(float *one, float *two)
{
    *one = *one - *two;
    *two = *one + *two;
    *one = *two - *one;
}