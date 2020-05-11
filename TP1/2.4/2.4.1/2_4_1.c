#include <stdio.h>
#include <ctype.h>

int main()
{
    int i = 0, printable = 0, non_printable = 0;
    printf("\n");
    do
    {
        if (isprint(i))
        {
            printf("%c", i);
            printable += 1;
        }
        else
        {
            non_printable += 1;
        }
        i++;
    } while (i <= 255);

    printf("\n\nThe total number of printable characters is %d\n", printable);
    printf("The total number of NON printable characters is %d\n", non_printable);
}