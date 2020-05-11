#include "func.h"

int main(int argc, char **argv)
{
    if (argc > 3)
    {
        char **file_names = (char **)malloc(sizeof(float *) * argc);
        int length;
        if (strcmp(argv[1], "-c") == 0)
        {
            printf("\nYou have chosen to perform compression.\n");

            for (int i = 3; i < argc; i++)
            {
                length = strlen(argv[i]);
                if (length < MAX_FNAME_LENGTH)
                {
                    file_names[i - 3] = (char *)malloc(sizeof(char) * length);
                    file_names[i - 3] = argv[i];
                }
                else
                {
                    printf("Closing...Too long name of the file number %d", i);
                    return 0;
                }
            }
        }
        file_packing(argv[2], argc - 3, file_names);
    }
    else
    {
        if (strcmp(argv[1], "-d") == 0)
        {
            printf("\nYou have chosen to perform decompression.\n");
            file_unpacking(argv[2]);
        }
    }
}