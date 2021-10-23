//создаем include guard файла операций над данными
#ifndef FILEOPS_H
#define FILEOPS_H

void save_bin_f(const void *ptr, int bytescount, const char *file);
void load_bin_f(void *ptr, int bytescount, const char *file);

#endif // !FILEOPS_H
