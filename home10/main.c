//подключаем стандартные библиотеки
#include <stdio.h>

//подключаем локальные библиотеки
#include "structs.h"
#include "fileops.h"

void main(void)
{
    printf("Hello\n");
    //объявление массива структуры для хранения 100 измерений
    struct data dataSet[100];

    int count = read_data_file(dataSet, "dataset.txt");
    if (count != 1) {
        print_data_file(dataSet, count);
    }
    //вывод структуры из массива в файле dataset.txt
    printf("data.txt elements : %d\n", read_data_file(dataSet, "dataset.txt"));
}