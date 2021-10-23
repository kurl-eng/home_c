#include "fileops.h"

#include <stdio.h>

/*        #include <stdio.h>

       size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);
 */

void save_bin_f(const void *ptr, int bytescount, const char *file)
{
    FILE *f;

    f = fopen(file, "wb");
    if (!f)
    {
        printf("ERROR save_binary_file\n");
        return;
    }
    size_t wr = fwrite(ptr, 1, bytescount, f);

    printf("write %lu bytes\n", wr);
    fclose(f);
}

void load_bin_f(void *ptr, int bytescount, const char *file)
{
    FILE *f;

    f = fopen(file, "rb");
    if (!f)
    {
        printf("ERROR load_binary_file\n");
        return;
    }
    size_t rd = fread(ptr, 1, bytescount, f);

    printf("load %lu bytes\n", rd);
    fclose(f);
}