#include "structs.h"
//создаем include guard файла операций над данными
#include "structs.h"
#ifndef FILEOPS_H
#define FILEOPS_H
//запись в файл измерений сенсора
int write_data_file(struct data_set *dataSet, int range, const char *file);
//чтение в структуру массива измерений из файла
int read_data_file(struct data_set *dataSet, const char *file);
//вывод структуры массива
void print_data_file(struct data_set *dataSet, int range);
//записать файл в бинарном виде
void save_bin_f(const void *ptr, int bytescount, const char *file);
//читать файл в бинарном виде
void load_bin_f(void *ptr, int bytescount, const char *file);

#endif // !FILEOPS_H
