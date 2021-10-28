#include "fileops.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int write_data_file(struct data_set *dataSet, int range, const char *file)
{
    FILE *f;
    //свойства функции зависят от значения второго аргумента
    //для перезаписи w/w+
    //для добавления в файл a/a+
    //эмулятор генерирует но не записывает при r/r+
    f = fopen(file, "w");
    if (!f)
    {
        return -1;
    }
    for (int i = 0; i < range; i++)
    {
        fprintf(f, "|%d\t|%d\t|%d\t|%d\n",
                dataSet[i].day,
                dataSet[i].month,
                dataSet[i].year,
                dataSet[i].temp);
    }
    fclose(f);
}

int read_data_file(struct data_set *dataSet, const char *file)
{
    FILE *f;
    int counter = 0;
    f = fopen(file, "r");
    if (!f)
    {
        return -1;
    }
    while (!feof(f))
    {
        int scans = fscanf(f, "|%d|%d|%d|%d",
                           &dataSet[counter].day,
                           &dataSet[counter].month,
                           &dataSet[counter].year,
                           &dataSet[counter].temp);
        if (scans != 4)
        {
            break;
        }
        counter++;
    }
    fclose(f);
    return counter;
}

void print_data_file(struct data_set *dataSet, int range)
{
    for (int i = 0; i < range; i++)
    {
        printf("Day: %d\t| Month: %d\t| Year: %d\t| Temperature: %d\n",
               dataSet[i].day,
               dataSet[i].month,
               dataSet[i].year,
               dataSet[i].temp);
    }
}

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