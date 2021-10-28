#include <stdio.h>
#include <stdlib.h>
#include "fileops.h"

int main (int argc, char **argv) 
{
    if (argc < 3) {
        printf("Формат копирования: %s filename filecopy\n", argv[0]);
        return 0;
    }
    file_cp(argv[1],argv[2]);

    return 0;
}
