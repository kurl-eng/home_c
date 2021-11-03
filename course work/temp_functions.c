#include "temp_functions.h"

#include <stdio.h>
#include <stdlib.h>

void sensor_emul(struct calendar *statistic, int range)
{
    for (int i = 0; i < range; i++) {
        statistic[i].year = rand() % 1 + 2021;
        statistic[i].month = rand() % 12;
        //statistic[i].week = rand() % 60 + 60;
        statistic[i].day = rand() % 30;
        statistic[i].hour = rand() % 24;
        statistic[i].minute = rand () % 60;
        statistic[i].temperature = 99 - rand() % 189;
    }
}

int write_stat_file(struct calendar *statistic, int range, const char *file)
{
    FILE *f_year;

    f_year = fopen("2021.csv", "w");

    if(!f_year) {
        printf("can't create file\n");
        return -1;
    }

    fprintf(f_year, "YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE\n");

    for (int i = 0; i < range; i++) {
        fprintf(f_year, "%4d;%2d;%2d;%2d;%2d;%2d\n",
                statistic[i].year,
                statistic[i].month,
                statistic[i].day,
                statistic[i].hour,
                statistic[i].minute,
                statistic[i].temperature
                );
    }
    fclose(f_year);
}

int read_stat_file(struct calendar *statistic, const char *file)
{
    FILE *f_year;
    int crnt = 0;
    f_year = fopen("2021.csv", "r");
    if (!f_year) {
        printf("No input file\n");
        return -1;
    }
    while (!feof(f_year)) {
        int scans = fscanf(f_year, "%4d;\t%2d;\t%2d;\t%2d;\t%2d;\t%2d\n",
                           &statistic[crnt].year,
                           &statistic[crnt].month,
                           &statistic[crnt].day,
                           &statistic[crnt].hour,
                           &statistic[crnt].minute,
                           &statistic[crnt].temperature
                           );
        if (scans != 6) {
            /* Приложение должно корректно работать на любых входных
            данных, если формат csv файла не соответствует заданному,
            то необходимо указать номер строки файла csv, в которой
            обнаружена ошибка и не учитывать данную строку. 
            */
            //continue;
            break;
        }
        crnt++;
    }
    fclose(f_year);
    return crnt;
}

void print_stat(struct calendar *statistic, int range)
{
    printf("YEAR\tMONTH\tDAY\tHOUR\tMINUTE\tTEMPERATURE\n");
    for (int i = 0; i < range; i++)
    {
        printf("%4d;\t%2d;\t%2d;\t%2d;\t%2d;\t%2d\n",
               statistic[i].year,
               statistic[i].month,
               statistic[i].day,
               statistic[i].hour,
               statistic[i].minute,
               statistic[i].temperature);
    }
}