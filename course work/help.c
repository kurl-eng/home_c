#include "help.h"

#include <stdio.h>

void help_com(const char *usage)
{
    printf("HELP MENU:\n");
    printf("To print file data, type: -f <filename.csv>\n");
    printf("WARNING! The key -f is required\n");
    printf("To print month statistic of file, type: -m [month]\n");
    printf("Program emulate current year only with name <year.csv>\n");
}