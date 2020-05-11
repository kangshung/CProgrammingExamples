#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum bool
{
    false,
    true
} bool;

void upper_lower(char *string, int length, bool flag);
int count_words(char *string, int length);
void print_stats(char **word_array, int counter);