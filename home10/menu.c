#include "menu.h"

#include <stdio.h>

//размер массива измерений
int input_days(int *range)
{
    printf("Введите количество дней: ");
    scanf("%d", range);
    return *range;
}

void print_days(const int *days)
{
    int print = *days;
    printf("В течении %d дней:\n", print);
    //return print;
}
