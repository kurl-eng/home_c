#include <stdio.h>
#include <string.h>

int input_days(int *days);

int print_days(int days);

void save_bin_f(const void *ptr, int bytescount, const char *file);

void load_bin_f(void *ptr, int bytescount, const char *file);

int read_data_file(struct data_set *measure, const char *file);

void print_data_file(struct data_set *measure, int range);

int main(void)
{
    int range;
    input_days(&range);
    print_days(range);

    struct data_set measure[range]
    {
        int day[31];
        int month[12];
        int year[3];
        int temp[100];
    };

    for (int i = 1; i <= range; i++)
    {
        measure[i].day[i];
        measure[i].month[i];
        measure[i].year[i];
        measure[i].year[i];
        printf("day %d\t", i);
        printf("month %d\t", i);
        printf("year %d\t", i);
        printf("temp %d\t\n", i);
    }

    int count = read_data_file(measure, "data.txt");
    //условие открытия файла
    if (count != -1)
    {
        print_data_file(measure, count);
    }

    save_bin_f(measure, range * sizeof(struct data_set), "data.bin");
    load_bin_f(measure, range * sizeof(struct data_set), "data.bin");

    print_data_file(measure, range);

    return 0;
}

void print_data_file(struct data_set *measure, int range)
{
    for (int i = 0; i < range; i++)
    {
        printf("Day:%d Month:%d Year:%d Temperature:%d\n",
               measure[i].day,
               measure[i].month,
               measure[i].year,
               measure[i].temp);
    }
}

int read_data_file(struct data_set *dataSet, const char *file)
{
    FILE *f;
    int counter = 0;
    f = fopen(file, "r");
    if (!f)
    {
        return -1;
    }
    while (!feof(f))
    {
        int scans = fscanf(f, "%d|%d|%d|%d",
                           &measure[counter].day,
                           &measure[counter].month,
                           &measure[counter].year,
                           &measure[counter].temp);
        if (scans != 4)
        {
            break;
        }
        counter++;
    }
    fclose(f);
    return counter;
}

void load_bin_f(void *ptr, int bytescount, const char *file)
{
    FILE *f;

    f = fopen(file, "rb");
    if (!f)
    {
        printf("ERROR load_binary_file\n");
        return;
    }
    size_t rd = fread(ptr, 1, bytescount, f);

    printf("load %lu bytes\n", rd);
    fclose(f);
}

void save_bin_f(const void *ptr, int bytescount, const char *file)
{
    FILE *f;

    f = fopen(file, "wb");
    if (!f)
    {
        printf("ERROR save_binary_file\n");
        return;
    }
    size_t wr = fwrite(ptr, 1, bytescount, f);

    printf("write %lu bytes\n", wr);
    fclose(f);
}

int print_days(int days)
{
    int print = days;
    printf("В течении %d дней:\n", print);
}

int input_days(int *days)
{
    printf("Введите количество дней\n");
    scanf("%d", days);
    return *days;
}
