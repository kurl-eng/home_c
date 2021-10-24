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

    int count = read_data_file(dataSet, "fdata.txt");
    //условие открытия файла
    if (count != -1) {
        print_data_file(dataSet, count);
    }

    save_bin_f(dataSet, 40 * sizeof(struct data_set), "structs.bin");

    //memset(dataSet, 0, 40* sizeof(struct data_set));
    //print_data_file(dataSet, 15);

    load_bin_f(dataSet, 40 * sizeof(struct data_set), "structs.bin");
    print_data_file(dataSet, 11);

    //вывод структуры из массива в файле data.txt
    printf("data.txt elements : %d\n", read_data_file(dataSet, "fdata.txt"));
}