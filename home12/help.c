#include "help.h"

#include <stdio.h>

void help_com(const char *usage)
{
    printf("usage: %s -s [original] -d [copy]\n", usage);
}