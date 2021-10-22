//работа с файлами происходит через библиотеку stdio.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//теперь для сборки программы нужно вводить все файлы
//*.с для сборки gcc main.c help.c -o main
#include "help.h"
#include "structs.h"
#include "fileops.h"

int main(void)
{
    /* struct user people[10];
    for (int i = 0; i < 10; i++) {
        people[i]. age = rand() % 50;
        //вывод строки с ограничетелем и форматом аргументов
        snprintf(people[i].surname, 30, "surname%d", rand() % 100);
        snprintf(people[i].name, 30, "name%d", rand() % 100);
    }

    //print_users(people, 10);
    //вывод аргументов в консоль
    printf("max age : %d\n", get_max_user_age(people, 10));
    printf("people with name27 : %d\n", get_user_for_name(people, 10, "name27"));
    sortUsersByAge(people, 10);
    print_users(people, 10);

    // user_t u = { 0 }; (1) ; (2)
    struct user u = { 0 };
    struct user u2 = { 0 };

    strcpy(u.name, "Vladimir");
    u.age = 30;

    strcpy(u2.name, "Alexander");
    u2.age = 25;

    print_user(u);
    print_user(u2);

    // print_help("test!");
    */

/*  //переменная типа FILE
    FILE *f;
    f = fopen("test.txt", "r");
    //char c;
    char str[50] = { 0 };
    //можно использовать scanf т.к. она обращалась неявно к
    //fscanf(stdin, "format")
    fscanf(f, "%s", str);
    printf("read %s\n", str);
    fclose(f);
*/

/*  while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    while (!feof(f)) {
        char c = fgetc(f);
        putchar(c);
    } 
*/

/*  char filename[50] = { 0 };
    scanf("%s", filename);
    //task 1
    printf("File test.txt size %d\n", get_file_size(filename));
    //task 2
    printf("File numbers summary : %d\n", get_file_numbers_summ(filename));
    file_append_digit_amount(filename);
*/

    struct measurements meas[100];
    int count = read_measurements_from_file(meas, "measurements.txt");
    if (count != 1) {
        print_measurements(meas, count);
    }
    printf("read meas %d\n", read_measurements_from_file(meas, "measurements.txt"));

    return 0;
}