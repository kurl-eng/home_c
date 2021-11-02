#include <stdio.h>
#include <stdlib.h>
#include "fileops.h"
char file_cp(const char *file1, const char *file2) 
{
FILE *f1 = fopen(file1, "rb");
FILE *f2 = fopen(file2, "wr");
unsigned char *buffer = (unsigned char *)malloc(sizeof(char) * 1024);
if (!f1 || !f2) { 
    printf("Unable to create/copy files\n");
    return -1;
}
while (1) {
    size_t rd = fread(buffer, 1024, 1, f1);
    size_t wr = fwrite(buffer, 1024, 1, f2);
    if (rd != wr) {
        printf("warning, copy file already exist\n");
    }
    if (feof(f1))
        break;
}
free(buffer);
fclose(f1);
fclose(f2);
}