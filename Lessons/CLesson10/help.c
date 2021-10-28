#include "help.h"
//для сохранения циклической зависимости
//подключаем библиотеки реализованных функицй
#include <stdio.h>

//реализации функций модульной программы
void print_help(const char *str)
{
    printf("HELP %s\n", str);
}