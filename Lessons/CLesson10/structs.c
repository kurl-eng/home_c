#include "structs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void print_user(user_t u) (1) ; (2)
void print_user(struct user u)
{
    printf("|name : %s |surname : %s |age : %d\n", u.name, u.surname, u.age);
}

void print_users(struct user *u, int N) 
{
    for (int i = 0; i < N; i++) {
        print_user(u[i]);
    }
}

int get_max_user_age(struct user *u, int N)
{
    //обьявляем переменную результата 
    //с точкой отсчета начала прохода по массива
    int max = u[0].age;
    for (int i = 0; i < N; i++) {
        //условие максимума сравнения текущего
        //и ячейки со значением переменной максимума
        if(u[i].age > max) {
            //присваиваем переменной
            //новый адрес маскимума
            max = u[i].age;
        }
    }
    return max;
}

int get_user_for_name(struct user *u, int N, const char *name)
{
    int count = 0;
    for (int i = 0; i < N; i++) {
        //используем функцию strcmp из библиотеки strin.h (man)
        if (strcmp(u[i].name, name) == 0) {
            count++;
        }
    }
    return count;
}

//Введем функицю сортировки для сравнения аргументов по параметрам элементов массива
static int comparer (const void *v1, const void *v2)
{
    struct user u1 = *(struct user*)v1;
    struct user u2 = *(struct user *)v2;
    //меняем порядок аргументов для изменения порядка сортировки
    return u1.age - u2.age;
}

void sortUsersByAge(struct user *u, int N) 
{
    //используем функцию qsort библиотеки stdlib.h
    qsort(u, N, sizeof(struct user), comparer);

}

int read_measurements_from_file(struct measurements *meas, const char *file)
{
    FILE *f;
    int counter = 0;
    f = fopen(file, "r");
    if (!f) {
        return -1;
    }
    while (!feof(f)) {
        int scans = fscanf(f, "%d;%d;%d;%d",
                           &meas[counter].day,
                           &meas[counter].month,
                           &meas[counter].year,
                           &meas[counter].temp
                           );
        if (scans != 4) {
            break;
        }
        counter++;
    }
    fclose(f);
    return counter;
}

void print_measurements(struct measurements *meas, int N)
{
    for (int i = 0; i < N; i++) {
        printf("|D:%d|M:%d|Y:%d|TEMP:%d|\n",
               meas[i].day,
               meas[i].month,
               meas[i].year,
               meas[i].temp);
    }
}
