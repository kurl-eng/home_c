#include <stdio.h>

void print_title(void);

int get_string(void);

void print_out(void);

int main(void)
{
    print_title();
    char string = get_string();
    print_out();

    return 0;
}

void print_out(void)
{
    get_string();
    printf("output %c\n", &get_string);
}

int get_string(void)
{
    char sign;
    putchar(sign);
    return sign;
}

void print_title(void)
{
    printf("Enter text with digits to count symbols of it: \n");
}
