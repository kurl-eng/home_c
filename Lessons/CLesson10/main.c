#include <stdio.h>
#include <string.h>
//теперь для сборки программы нужно вводить все файлы
//*.с для сборки gcc main.c help.c -o main
#include "help.h"
#include "structs.h"

int main(void)
{
    // user_t u = { 0 }; (1) ; (2)
    struct user u = { 0 };
    strcpy(u.name, "Vladimir");
    u.age = 30;

    print_user(u);
    print_help("test!");
    return 0;
}