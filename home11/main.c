#include <stdio.h>
#include <string.h>
#include "dirops.h"
#include <unistd.h>

/*int main(void)
{
    //char *getcwd(char *buf, size_t size);
    char cwd[254] = { 0 };
    getcwd(cwd, 254);
    cwd[253] = 0;
    //printf("cwd %s\n", cwd);
    //dirls(cwd, true);
    return 0;
}*/

int main (int argc, char **argv) 
{
    /*printf("argc %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);
    }*/
    
    if (argc < 2) {
        printf("Введите аргумент(путь к директории)\n");
        return 0;
    }
    if (argc == 3 && argv[2][0] == 'h')
        dirls(argv[1], true);
    else
        dirls(argv[1], false);
}