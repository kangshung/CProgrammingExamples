#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FNAME_LENGTH 256
#define MAX_UINT 10

struct filestructure
{
    char filename[MAX_FNAME_LENGTH];
    unsigned int num_of_bytes;
};
typedef struct filestructure filestruct;

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names);
void file_unpacking(char *packed_file_name);