#include "fileops.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1024

char file_cp(const char *f_src, const char *f_dst)
{
    if (!f_dst || !f_src)
    {
        printf("to define correctly name of files use ls command\n");
        printf("to help, type ./copy -h\n");
        return -1;
    }

    FILE *fsrc = fopen(f_dst, "rb");
    FILE *fdst = fopen(f_dst, "wr");

    unsigned char *buffer = (unsigned char *)malloc(sizeof(char) * BUFFER);
    
    if (!f_dst || !f_src) {
        printf("Unable to open file\n");
        return -1;
    }

    while (1) {
        size_t rd = fread(buffer, 1, BUFFER, fsrc);
        size_t wr = fwrite(buffer, 1, BUFFER, fdst);
        if (rd != wr) {
            printf("error data file\n");
            return -1;
        }
        if (feof(fsrc))
            break;
        printf("copy file: [%s] already exist\n", fdst);
    }
    free(buffer);
    fclose(fsrc);
    fclose(fdst);
}