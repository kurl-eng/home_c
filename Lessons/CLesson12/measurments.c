#include <stdio.h>
#include <stdlib.h>

struct measurement {
    int day;
    int month;
    int year;
    int temp;
};

int main (int argc, char **argv)
{
    const char *fname = "output.txt";

    FILE *f = fopen(fname, "w");
    if (!f) {
        printf("ERROR!\n");
        return -1;
    }

    struct measurement meas[31]; //0-30
    //заполнить счетчик с учетем месяцов и лет
    //например после 31 дня + 1 месяц и т.д.
    for (int i = 0; i < 31; i++) {
        meas[i].day = i + 1;
        meas[i].month = 2;
        meas[i].year = 2000;
        meas[i].temp = rand() % 10 - 10;
        //fprintf(f, "|%d\t|%d\t|%d\t|%d\n", day, 4, 1990, rand() % 20 - -5);
    }

    for (int i = 0; i < 31; i++) {
        fprintf(f, "|%d\t|%d\t|%d\t|%d\n",
                meas[i].day,
                meas[i].month,
                meas[i].year,
                meas[i].temp
                );
    }

    fclose(f);
    return 0;
}