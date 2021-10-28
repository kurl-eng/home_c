#include <stdio.h>
#include <stdlib.h>
#include "fileops.h"
void file_cp(const char *file1, const char *file2) 
{
FILE *f1 = fopen(file1, "rb");
FILE *f2 = fopen(file2, "wr");
unsigned char *buffer = (unsigned char *)malloc(sizeof(char) * 1024);
while (1) {
    size_t rd = fread(buffer, 1024, 1, f1);
    size_t wr = fread(buffer, 1024, 1, f1);
    if (rd != wr)
    {
        printf("error data file\n");
    }
    if (feof(f1))
        break;
}
free(buffer);
fclose(f1);
fclose(f2);
}