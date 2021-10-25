#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "structs.h"

int main(void)
{
    int range;
    input_days(&range);
    //проверка принятие переменной значения функции
    //printf("В течении %d дней:\n", range);
    print_days(&range);
    struct data_set measure[range];
    for (int i = 0; i < range; i++) {
        measure[range].day[i] = rand() % 31;
        measure[range].month[i] = rand() % 12;
        measure[range].year[i] = rand() % 2021 - 21;
        measure[range].temp[i] = rand() % 100 - 50;
        //snprintf(measure[range].month[i], 12, "%d", rand() % 12);
    }
    
    print_measures(measure, range);

    return 0;
}

