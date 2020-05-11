#include "func.h"

char *search_regex(char *text, char *pattern)
{
    regex_t regex_compiled;
    regmatch_t results;
    regcomp(&regex_compiled, pattern, REG_EXTENDED);
    regexec(&regex_compiled, text, 1, &results, 0);
    int start, end;
    start = results.rm_so;
    end = results.rm_eo;
    char cursor[strlen(text) + 1];
    strcpy(cursor, text);
    cursor[results.rm_eo] = 0;
    char *result = cursor + results.rm_so;
    regfree(&regex_compiled);
    return result;
}

int count_occurences(char *substring, char *text)
{
    int count = 0, count1 = 0;
    int i, j, l, l1, l2;

    l1 = strlen(text);
    l2 = strlen(substring);
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while (text[i] == substring[j])
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;
            count = 0;
        }
        else
            i++;
    }
    return count1;
}

char *parse_one_tag(char *start_pattern, char *end, char *text)
{
    int l = strlen(text);
    char *start = strstr(text, start_pattern);
    char *after_first = strstr(start, ">") + 1;
    char *end_pointer = strstr(after_first, end);
    size_t len = end_pointer - after_first;

    char *result = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(result, after_first, len);
    result[len] = 0;

    return result;
}

void parse_tags(char *start, char *end, char *text, int occurences, char *results[])
{
    char *cursor = text;
    for (int i = 0; i < occurences; i++)
    {
        results[i] = parse_one_tag(start, end, cursor);
        cursor = strstr(cursor, end) + 1;
    }
}

void print_indices(stock *indexes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Stock id: #%d\nStock name: %s\nStock current_price: %s\nStock day_change: %s\n\n", i + 1, indexes[i].name, indexes[i].current_price, indexes[i].day_change);
    }
}

char *str_replace(char *orig, char *rep, char *with)
{
    char *result, *ins, *tmp;
    int len_rep, len_with, len_front, count;

    if (!orig || !rep)
    {
        return NULL;
    }
    len_rep = strlen(rep);
    if (len_rep == 0)
    {
        return NULL;
    }
    if (!with)
    {
        with = "";
    }
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count)
    {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
    {
        return NULL;
    }

    while (count--)
    {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep;
    }
    strcpy(tmp, orig);
    return result;
}

stock parse_one_index(char *text)
{
    char *cursor = text;
    stock index;

    cursor = strstr(cursor, "</td>") + 1;
    index.name = parse_one_tag("<a", "</a>", parse_one_tag("<td", "</td>", cursor));
    cursor = strstr(cursor, "</td>") + 1;

    index.current_price = str_replace(parse_one_tag("<span", "</span>", cursor), ",", "");
    cursor = strstr(cursor, "</td>") + 1;
    index.day_change = parse_one_tag("<span", "</span>", cursor);

    return index;
}

void swap(stock *xp, stock *yp)
{
    stock temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_indices(stock *indexes, int n, int order)
{
    int i, j;
    char *eptr;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (order == 1 && strcmp(indexes[j].name, indexes[j + 1].name) > 0)
            {
                swap(&indexes[j], &indexes[j + 1]);
            }
            else if (order == 2 && strtod(indexes[j].current_price, &eptr) > strtod(indexes[j + 1].current_price, &eptr))
            {
                swap(&indexes[j], &indexes[j + 1]);
            }
            else if (order == 3 && strtod(indexes[j].day_change, &eptr) > strtod(indexes[j + 1].day_change, &eptr))
            {
                swap(&indexes[j], &indexes[j + 1]);
            }
        }
    }
}