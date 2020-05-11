#include "func.h"

int main(int argc, char *argv[])
{
    // system("wget -qO stocks.txt https://www.hl.co.uk/shares/stock-market-summary/ftse-100");

    int sort_flag = 0;
    if (argc == 2)
    {
        sort_flag = atoi(argv[1]);
    }

    long size;
    FILE *ptr;

    ptr = fopen("stocks-06-april-2020.txt", "r");
    fseek(ptr, 0, SEEK_END);
    size = ftell(ptr);
    fseek(ptr, 0, SEEK_SET);

    char *html = malloc(size * sizeof(char));
    fread(html, size, sizeof(char), ptr);
    fclose(ptr);

    char *tbody = search_regex(html, "(<tbody>)(.*)(</tbody>)");
    int no_of_rows = count_occurences("</tr>", tbody);
    char *results[no_of_rows];
    parse_tags("<tr", "</tr>", tbody, no_of_rows, results);

    stock indexes[no_of_rows];
    for (int i = 0; i < no_of_rows; i++)
    {
        indexes[i] = parse_one_index(results[i]);
    }

    if (sort_flag)
    {
        sort_indices(indexes, no_of_rows, sort_flag);
    }
    print_indices(indexes, no_of_rows);
    free(html);
}