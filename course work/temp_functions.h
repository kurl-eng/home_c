#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

/*#define MONTH *12 YEAR
#define WEEK *4 MONTH
#define DAY *7 WEEK
#define HOUR *24 DAY
#define MINUTE *60 HOUR
#define SECOND *60 MINUTE
#define SECOND 1*/

struct calendar
{
    int minute;
    int hour;
    int day;
    //int week;
    int month;
    int year;
    int temperature;
};

//эмулятор генерирует случайную за год статистику в массив
void sensor_emul(struct calendar *statistic, int range);

//запись результатов генерации эмулятора в файл *.csv
int write_stat_file(struct calendar *statistic, int range, const char *file);

//чтение статистики из файла
int read_stat_file(struct calendar *statistic, const char *file);

//вывод статистики в консоль
void print_year_stat(struct calendar *statistic, int range);

//статистика за месяц
void print_month(struct calendar *statistic, int range);

#endif // !TEMP_FUNCTIONS_H
