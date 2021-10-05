#include <stdio.h>

void print_title(void);
void print_count(void);

int get_string(void);

void lenght_absolute(void);

void digits_absolute(void);
void digits_percent(void);

void high_absolute(void);
void high_percent(void);

void low_absolute(void);
void low_percent(void);

void spaces_absolute(void);
void spaces_percent(void);

int main(void)
{
    print_title();
    int value = 0;
    value = get_int();

    return 0;
}

void spaces_percent(void)
{

}

void spaces_absolute(void)
{

}

void low_percent(void)
{

}

void low_absolute(void)
{

}

void high_percent(void)
{

}

void high_absolute(void)
{

}

void digits_percent(void)
{

}

void digits_absolute(void)
{

}

void lenght_absolute(void)
{
    char sign;
    int sum = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
    }
    return sum;
}

int get_string(void)
{
    char sign;
    int number = 0;

    while ((sign = getchar()) != '\n')
    {
        if (sign >= '0' && sign <= '9')
        {
            number *= 10;
            number += sign - '0';
        }
    }
    return number;
}

void print_count(void)
{
    printf("");
    printf("");
    printf("");
}

void print_title(void)
{
    printf("Enter text with digits to count values of it: \n");
}
