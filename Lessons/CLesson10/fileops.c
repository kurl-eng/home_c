#include "fileops.h"
#include <stdio.h>

int get_file_size(const char *filename)
{
    FILE *f;
    long sz;

    f = fopen(filename, "r");
    if (!f) {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    sz = ftell(f);

    fclose(f);
    //для чего то вот
    //rewind();
    return sz;
}

int get_file_numbers_summ(const char *filename)
{
    FILE *f;
    int tmp;
    int summ = 0;

    f = fopen(filename, "r");
    if (!f) {
        return -1;
    }

    while (fscanf(f, "%d", &tmp) == 1) {
        summ += tmp;
    }
    
    fclose(f);
    return summ;
}

void file_append_digit_amount(const char *filename)
{
    FILE *f;
    char c;
    int digits = 0;
    f = fopen(filename, "r+");
    if (!f) {
        printf("ERROR\n");
        return;
    }
    while ((c = fgetc(f)) != EOF) {
        if (c >= '0' && c <= '9') {
            //printf("digit %c\n", c);
            digits++;
        }
    }
    fprintf(f, " %d", digits);
    fclose(f);
}