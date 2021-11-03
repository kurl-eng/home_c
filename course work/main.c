#include <stdio.h>
#include <unistd.h>

#include "help.h"
#include "temp_functions.h"

#define YEAR 365
/*#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12*/

#if defined DEBUG
#define DBG(x) printf("%s, func: %s, line: %d\n", x, __func__, __LINE__)
#else
#define DBG(x)
#endif

int main(int argc, char **argv)
{
    const char *file_stat = NULL;
    struct calendar statistic[YEAR];
    sensor_emul(statistic, YEAR);
    write_stat_file(statistic, YEAR, optarg);

    if (argc < 2) {
        printf("For help type: sensor -h\n");
        //help_com(argv[0]);
    }

    int com;
    while((com = getopt(argc, argv, "f:mh")) != -1) {
        switch (com) {
        case 'f': {
            file_stat = optarg;
            //оставляет ввод в консоль!?
            read_stat_file(statistic, optarg);
            //эта функция же читает из эмудятора?
            //а я хочу из файла
            //понял что это из за contine
            print_stat(statistic, YEAR);
            return 0;
            break;
        }
        case 'm' : {
            break;
        }
        case 'h' : {
            help_com(argv[0]);
            break; }
        /*default  : { 
            printf("to help, type: sensor -h\n");
            break; }*/
        }
    }
}