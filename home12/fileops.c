#include "fileops.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1024
#if defined DEBUG
#define DBG(x) printf("%s, func: %s, line: %d\n", x, __func__, __LINE__)
#else
#define DBG(x)
#endif

char file_cp(const char *f_src, const char *f_dst)
{
    FILE *fsrc = fopen(f_src, "rb");
    FILE *fdst = fopen(f_dst, "wr");

    unsigned char *buffer = (unsigned char *)malloc(sizeof(char) * BUFFER);

    if (!fsrc || !fdst) {
        DBG("Unable to open files");
        printf("to define correctly name of files use ls command\n");
        printf("to help, type ./copy -h\n");
        return -1;
    }

    while (1) {
        size_t rd = fread(buffer, 1, BUFFER, fsrc);
        size_t wr = fwrite(buffer, 1, rd, fdst);
        if (rd != wr) {
            DBG("warning! Not all contents read/wrote");
            printf("error data file\n");
            return -1;
        }
        if (feof(fsrc))
            break;
    }
    printf("copy file: [%s] already exist\n", f_dst);
    free(buffer);
    fclose(fsrc);
    fclose(fdst);
}