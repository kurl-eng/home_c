#ifndef STRUCTS_H
#define STRUCTS_H

//дирректива для выравнивания объема данных
//#pragma pack(push, 1)

struct user {
    //компилятор выравнивает объем данных для процессора
    //в зависимости от порядка расположения переменных
    char surname[30];
    char name[30]; //30
    int age; //4
    //short height; //2
    //unsigned char weight; //1
}; //user_t; (2)

//#pragma pack(pop)

// typedef struct user user_t; (1)
// void print_user(user_t u); (1)

//typedef struct user user_t; (2)

void print_user(struct user u);
void print_users(struct user *u, int N);
//сортировка людей по возрасту
void sortUsersByAge(struct user *u, int N);

/* Описать структуру для представления информации о человеке: фамилия (не
более 30 символов), имя (не более 30 символов), возраст. Описать функцию,
которая для заданного массива из описанных структур определяет: */
//a. возраст самого старшего человека;
int get_max_user_age(struct user *u, int N);
//b. количество людей с заданным именем (имя также является параметром функции);
int get_user_for_name(struct user *u, int N, const char *name);
//c. количество людей, у которых есть однофамильцы;

/* Описать структурный тип для представления сбора информации с датчика
температуры, необходимые поля: дата (день, месяц, год) и температура.
Используя этот тип, описать функцию, принимающую на вход массив таких
данных и упорядочивающую его по неубыванию, по дате. */

struct measurements {
    int day;
    int month;
    int year;
    int temp;
};


int read_measurements_from_file(struct measurements *meas, const char *file);

void print_measurements(struct measurements *meas, int N);

#endif