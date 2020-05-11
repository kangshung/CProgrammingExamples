#include "func.h"

void upper_lower(char *string, int length, bool flag)
{
    if (flag)
    {
        for (int i = 0; i < length; i++)
        {
            string[i] = toupper(string[i]);
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            string[i] = tolower(string[i]);
        }
    }
}

int count_words(char *string, int length)
{
    int words = 1;
    for (int i = 0; i < length; i++)
    {
        if (string[i] == ' ')
        {
            words += 1;
        }
    }
    return words;
}

void print_stats(char **word_array, int counter)
{
    printf("\nThe total number of words is: %d", counter);
    int total_length = 0;
    for (int i = 0; i < counter; i++)
    {
        // printf("%s\n", word_array[i]);
        total_length += strlen(word_array[i]);
    }
    printf("\nThe average number of letters per word is: %f\n", (float)(total_length - 1) / (float)counter);
}