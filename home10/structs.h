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
//эмулятор измерений величиной введенной пользователем
void emul_measures(struct data_set *measure, int range);
//формат вывода измерения
void print_measure(struct data_set measure);
//цикл вывода массива измерений
void print_measures(struct data_set *measure, int range);
#endif // !STRUCT_H