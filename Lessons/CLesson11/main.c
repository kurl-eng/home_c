#include <stdio.h>
#include <unistd.h>
#include "dirops.h"

//getcwd
/*int main(void)
{
    //получить текущий рабочий каталог
    char cwd[255] = { 255 };
    getcwd(cwd, 254);
    cwd[254] = 0;
    //printf("cwd %s\n", cwd);
    dirls(cwd, false);
    return 0;
}*/

//каноничный main двумерный массив
//в argc - аргументы переданные программе
//в argv - все введенные аргументы
//по умолчанию в виде аргумента в программу передается имя исполняемой программы
int main(int argc, char **argv)
{
    /*printf("argc %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);
    }*/

    if (argc < 2) {
        printf("Введите аргумент (путь к директории)\n");
        return 0;
    }

    if (argc == 3 && argv[2][0] == 'y') {
        dirls(argv[1], true);
    } else {
        //вызов функции программы для работы со вторым элементом массива
        dirls(argv[1], false);
    }
    
}