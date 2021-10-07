#include <stdio.h>
#include <stdbool.h>

void print_title(void);

char get_string(char sign);

void count_numbers(void);

int main(void)
{
    print_title();
    

    count_numbers();

    printf("\n");
    return 0;
}

void count_numbers(void)
{
    char number;
    int count = 0;
    while ((number = getchar()) != '\n') {
        if (number >= '0' && number <= '9') {
            putchar(number);
            count++;
        }
    }
    printf("\nnumber of digits in string %c is : %d\n", number, count);
}

char get_string(char sign)
{
    while ((sign = getchar()) != '\n')
    {
        putchar(sign);
    }
    return sign;
}

void print_title(void)
{
    printf("Enter text with digits to count symbols of it : \n");
}
