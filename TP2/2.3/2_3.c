#include "func.h"

int main(int argc, char **argv)
{
    int length = 0;
    char *string = NULL;
    bool flag;
    if (argc == 1)
    {
        string = (char *)malloc(sizeof(char) * 1);
        char input = getchar();
        while (input != '\n')
        {
            *(string + length++) = input;
            string = (char *)realloc(string, length);
            input = getchar();
        }
        *(string + length) = '\n';
    }
    else
    {
        string = argv[1];
    }

    printf("Please choose if you want to change your string to lower-case (type 0) or upper-case (type 1)\n");
    scanf("%d", &flag);
    upper_lower(string, length, flag);
    printf("\nHere is the text that you gave after changing the case:\n%s", string);

    int words_counter = count_words(string, length);
    char **word_array = (char **)malloc(sizeof(char *) * words_counter);

    word_array[0] = strtok(string, " ");
    if (words_counter > 1)
    {
        for (int i = 1; i < words_counter; i++)
        {
            word_array[i] = strtok(NULL, " ");
        }
    }

    print_stats(word_array, words_counter);

    free(word_array);
    if (argc == 1)
    {
        free(string);
    }
}
