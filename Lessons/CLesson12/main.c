#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//для функции getopt работы с командной строкой
#include <unistd.h>

//пример макроса для ДЗ
//#define DBG (n, x) printf("scans %d, %d%d%d%d\n", n, x.day, x.month, x.year, x.temp)

#define BUFFER 1024
//#define DBG(x) printf("debug %s\n", x)
//рекурсивная замена макросов
//#define DBG2 DBG
//при использовании арифметических операций,
//лучше очевидно обозначать последовательность скобками
//#define MAX(a, b) ((a < b) ? b : a)
//аналогично макросу и макрос экономит ресурсы
int my_max(int a, int b)
{
    return a < b ? b : a;
}

// (1)
//#define DEBUG

//проведем отладку методом трассировки
#if defined DEBUG
#define DBG(x) printf("%s func: %s: %d\n", x, __func__, __LINE__)
#else
#define DBG(x)
#endif
//удобство использование макросов заключается
//в переносимости кода на разные платформы
//#ifdef __linux__
#ifndef __linux__
#warning Not a linux kernel
#endif


/*#if defined APPLE
#else
#warning "Not a MacOS"
//#error "Not a MacOS"
#endif*/

/* man fopen; fread; feof stat; 2 getopt */
//динамическое выделение памяти malloc; strdup; realloc
//взять данные стат чтобы понять сколько копировать

extern char *optarg;
extern int optind, opterr, optopt;

void print_help(const char *message)
{
    printf("usage: %s -s [source file] -d [destination file]\n", message);
}

//комментирование с помощью макросов
//#ifdef COMMENT
//#if 0 (1)
int main(int argc, char **argv)
{
    // s - source
    // d - destination
    const char *f_src = NULL;
    const char *f_dst = NULL;

    DBG("Initialization");

    //printf("max %d\n", MAX(10, 5));
    //DBG("test");
    // printf("debug %s\n", "test");

    opterr = 0;
    //зададим условие принятие аргументов из командной строки через -' '
    int ret;
    //при s::d: с ':' опции выполняются обязательно
    // while ((ret = getopt(argc, argv, "s::d:")) != -1)
    while ((ret = getopt(argc, argv, "sdh")) != -1) {
        switch (ret) {
            case 's' : {
                DBG("getopt found source file");
                //printf("Found source option string %s optind %d optopt %d opterr %d\n",
                //        optarg, optind, optopt, opterr);
                //f_src = argv[optind];
                f_src = optarg;
                break;
            }
            case 'd' : {
                DBG("getopt found destination file");
                //printf("Found destination option string %s optind %d optopt %d opterr %d\n",
                //        optarg, optind, optopt, opterr);
                //f_dst = argv[optind];
                f_src = optarg;
                break;
            }
            case 'h' : {
                print_help(argv[0]);
                return 0;
                break;
            }
            case '?' : {
                DBG("Found unknown option");
                //printf("Found unknown option string\n");
                break;
            }
        }
    }

    if (!f_dst || !f_src) {
        //printf("Source and destination files are not defined\n");
        return -1;
    }

    /*return 0;

    if(argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return -1;
    }*/
    //const char *f_src = argv[1];
    //const char *f_dst = argv[2];

    FILE *fsrc = fopen(f_src, "rb"); //read binary
    FILE *fdst = fopen(f_dst, "wr"); //write binary
    //буферный массив для блочного копирования в статическом виде
    //unsigned char array[BUFFER];
    //выделяем память функцией malloc * с явным преобразованием в динамическом виде
    unsigned char *array = (unsigned char*) malloc (sizeof(char) * BUFFER);
    //нельзя дважды подряд вызывать malloc
    //array = malloc(sizeof(char) * BUFFER);

    //пример работы для изменения размера массива 
    //array = realloc(array, BUFFER * 2);

    if (!f_src || !f_dst) {
        DBG("Unable to open file");
        //printf("Unable to open file\n");
        return -1;
    }

    while (1) {
        /* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

        size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                      FILE *stream); */
        size_t rd = fread(array, 1, BUFFER, fsrc);
        //printf("rd %lu\t", rd);
        size_t wr = fwrite(array, 1, rd, fdst);
        
        if (rd != wr) {
            DBG("warning! Not all contents read/wrote");
            //printf("warning! Not all contents read/wrote\n");
        }
        if (feof(fsrc))
            break;
    }
    //освобождаем память при использовании malloc функции
    free(array);
    //нельзя дважды высвобождать память после malloc
    //free(array);

    fclose(fsrc);
    fclose(fdst);
    //cp <f1> => <f2>
    return 0;
}

//конец комментария
//#endif