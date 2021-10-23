//подключаем стандартные библиотеки
#include <stdio.h>
#include <string.h>

//подключаем локальные библиотеки
#include "menu.h"
#include "fileops.h"
#include "structs.h"



int main(void)
{   
    print_hello("Welcome");

    //объявление массива структуры для хранения 100 измерений
    struct data_set dataSet[40];

    /*for (int i = 0; i < 30; i++) {
        dataSet[i].day = rand() % 31;
        dataSet[i].month = rand() % 12;
        dataSet[i].year = 2000 + rand() % 21;
        dataSet[i].temp = -30 + rand() % 60;
        snprintf(dataSet[i].day, 30, "%d");
        snprintf(dataSet[i].month, 30, "%d");
        snprintf(dataSet[i].year, 30, "%d");
        snprintf(dataSet[i].temp, 30, "%d");
    }*/

    int count = read_data_file(dataSet, "fdata.txt");
    //условие открытия файла
    if (count != -1) {
        print_data_file(dataSet, count);
    }

    save_bin_f(dataSet, 40 * sizeof(struct data_set), "structs.bin");

    memset(dataSet, 0, 40* sizeof(struct data_set));
    print_data_file(dataSet, 15);

    load_bin_f(dataSet, 40 * sizeof(struct data_set), "structs.bin");
    print_data_file(dataSet, 15);

    //вывод структуры из массива в файле data.txt
    printf("data.txt elements : %d\n", read_data_file(dataSet, "fdata.txt"));
}