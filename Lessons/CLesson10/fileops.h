#ifndef FILEOPS_H
#define FILEOPS_H

/* 1. Дан текстовый файл in.txt, содержащий целые числа. Посчитать сумму чисел.
   2. Ввести имя файла и напечатать его размер.
   3. Дан текстовый файл in.txt. Необходимо посчитать количество цифр в файле и
дописать это число в конец данного файла. */

int get_file_numbers_summ(const char *filename);
int get_file_size(const char *filename);
void file_append_digit_amount(const char *filename);

#endif