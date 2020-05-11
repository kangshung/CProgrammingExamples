#include "func.h"

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names)
{
    FILE *open = NULL;
    char *data = (char *)malloc(sizeof(char));
    int offset = 0;
    unsigned int num_bytes = 0;
    filestruct metadata[num_of_files * sizeof(filestruct)];

    for (int i = 0; i < num_of_files; i++)
    {
        open = fopen(array_of_names[i], "rb");
        fseek(open, 0, SEEK_END);
        num_bytes = ftell(open);
        fseek(open, 0, SEEK_SET);

        data = (char *)realloc(data, sizeof(data) + offset);
        fread(data + offset, sizeof(char), num_bytes, open);

        metadata[i].num_of_bytes = num_bytes;
        strcpy(metadata[i].filename, array_of_names[i]);

        offset = offset + num_bytes;
        fclose(open);
    }

    offset = 0;
    open = fopen(packed_file_name, "wb");
    for (int i = 0; i < num_of_files; i++)
    {
        fprintf(open, "%.10u", metadata[i].num_of_bytes);
        fwrite(&metadata[i], sizeof(char), MAX_FNAME_LENGTH, open);
        fwrite(&data[offset], sizeof(char), metadata[i].num_of_bytes, open);
        offset = offset + metadata[i].num_of_bytes;
    }
    fclose(open);
    free(data);
};

void file_unpacking(char *packed_file_name)
{
    FILE *open = NULL;
    char *data = (char *)malloc(sizeof(char));
    char file[MAX_UINT], file_name[MAX_FNAME_LENGTH], command[666], path[666];
    unsigned int file_size = 0, num_bytes = 0;
    int offset = 0;

    open = fopen(packed_file_name, "r");
    fseek(open, 0, SEEK_END);
    num_bytes = ftell(open);
    fseek(open, 0, SEEK_SET);

    data = (char *)realloc(data, num_bytes);
    fread(data, sizeof(char), num_bytes, open);
    fclose(open);

    system("mkdir decompressed");
    while (data[offset] != 0)
    {
        memcpy(file, &data[offset], MAX_UINT);
        file_size = atoi(file);
        offset = offset + MAX_UINT;
        memcpy(file_name, &data[offset], sizeof(file_name));
        offset = offset + MAX_FNAME_LENGTH;

        sprintf(command, "touch decompressed/%s", file_name);
        system(command);

        sprintf(path, "decompressed/%s", file_name);
        open = fopen(path, "w");
        fwrite(&data[offset], sizeof(char), file_size, open);
        fclose(open);

        offset = offset + file_size;
    }
    free(data);
};