//создаем include guard файла структур данных
#ifndef STRUCTS_H
#define STRUCTS_H

//объявление структур данных
struct data_set {
    int day;
    int month;
    int year;
    int temp;
};

//чтение в структуру массива измерений из файла
int read_data_file(struct data_set *dataSet, const char *file);

//вывод структуры массива
void print_data_file(struct data_set *dataSet, int range);

#endif // !STRUCT_H