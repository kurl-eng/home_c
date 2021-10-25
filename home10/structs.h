//создаем include guard файла структур данных
#ifndef STRUCTS_H
#define STRUCTS_H

//объявление структур данных
struct data_set {
    int day[31];
    int month[12];
    int year[10];
    int temp[100];
};

void print_measure(struct data_set measure);

void print_measures(struct data_set *measure, int range);

//чтение в структуру массива измерений из файла
int read_data_file(struct data_set *dataSet, const char *file);

//вывод структуры массива
void print_data_file(struct data_set *dataSet, int range);

#endif // !STRUCT_H