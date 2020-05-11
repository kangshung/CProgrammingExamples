#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct
{
    char *name;
    char *current_price;
    char *day_change;
} stock;

char *search_regex(char *text, char *pattern);
int count_occurences(char *substring, char *text);
char *parse_one_tag(char *start_pattern, char *end, char *text);
void parse_tags(char *start, char *end, char *text, int occurences, char *results[]);
void print_indices(stock *indexes, int n);
char *str_replace(char *orig, char *rep, char *with);
stock parse_one_index(char *text);
void swap(stock *xp, stock *yp);
void sort_indices(stock *indexes, int n, int order);