#include <stdio.h>
#include <stdlib.h>

int main()
{
    float values[666];
    FILE *ptr;
    ptr = fopen("function_data_bin", "rb");
    fread(values, sizeof(values), 1, ptr);
    fclose(ptr);

    FILE *write_ptr;
    write_ptr = fopen("trig", "w");
    for (int i = 0; i < 200; i++)
    {
        fprintf(write_ptr, "%f %f\n", values[i], values[i + 200]);
    }
    fclose(write_ptr);

    system("gnuplot -p -e 'plot \"trig\"'");
}