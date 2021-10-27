#ifndef DIROPS_H
#define DIROPS_H
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_type(const struct stat *st);
void dirls(const char *path, bool hidden);

#endif