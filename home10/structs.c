#include <stdio.h>

//подключим библиотеку определения функций для реализации
#include "structs.h"

void print_measure(struct data_set measure)
{
    printf("%ls|%ls|%ls|%ls", measure.day, measure.month, measure.year, measure.temp);
}

void print_measures(struct data_set *measure, int range)
{
    for (int i = 0; i < range; i++) {
        print_measure(measure[i]);
    }
}

//чтение структуры массива измерений из файла
/*int read_data_file(struct data_set *dataSet, const char *file)
{
    FILE *f;
    int counter = 0;
    f = fopen(file, "r");
    if (!f) {
        return -1;
    }
    while (!feof(f)) {
        int scans = fscanf(f, "%d|%d|%d|%d", &dataSet[counter].day,
                                             &dataSet[counter].month,
                                             &dataSet[counter].year,
                                             &dataSet[counter].temp
                                             );
        if (scans != 4) {
            break;
        }
        counter++;
    }
    fclose(f);
    return counter;
}*/

/*void print_data_file(struct data_set *dataSet, int range)
{
    for (int i = 0; i < range; i++) {
        printf("Day:%d Month:%d Year:%d Temperature:%d\n", dataSet[i].day,
                                                           dataSet[i].month,
                                                           dataSet[i].year,
                                                           dataSet[i].temp 
                                                           );
    }
}*/