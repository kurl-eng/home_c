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
    size_t rd = fread(buffer, 1, 1024, f1);
    //printf("rd %lu\n", rd);
    size_t wr = fwrite(buffer, 1, rd, f2);
    if (rd != wr) {
        printf("error data file\n");
        return -1;
    }
    if (feof(f1))
        break;
}
printf("copy file: [%s] already exist\n", file2);
free(buffer);
fclose(f1);
fclose(f2);
}