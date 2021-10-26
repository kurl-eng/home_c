#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void emul_measures(struct data_set *measure, int range)
{
    for (int i = 0; i < range; i++)
    {
        measure[i].day = rand() % 30 + 1;
        measure[i].month = rand() % 12;
        measure[i].year = rand() % 2021;
        measure[i].temp = rand() % 100 - 50;
    }
}
void print_measure(struct data_set measure)
{
    printf("Day: %d\t| Month: %d\t| Year: %d\t| Temperature : %d\n", 
            measure.day,
            measure.month, 
            measure.year, 
            measure.temp
            );
}
void print_measures(struct data_set *measure, int range)
{
    for (int i = 0; i < range; i++) {
        print_measure(measure[i]);
    }
}
