#include <stdio.h>
#include <stdbool.h>
void print_title(void);
void count_string(void);
int main(void)
{
    print_title();
    count_string();
    printf("\n");
    return 0;
}
void count_string(void)
{
    char sign;
    int count_signs = 0;
    int count_digits = 0;
    //float percentage_digits = (count_digits % count_signs);
    int count_high_signs = 0;
    //float percentage_high_signs = (count_high_signs % count_signs);
    int count_low_signs = 0;
    //float percentage_low_signs = (count_low_signs % count_signs);
    int count_spaces = 0;
    //float percentage_spaces = (count_spaces % count_signs);
    while ((sign = getchar()) != '\n')
    {
        if (sign >= '0' && sign <= 'z') {count_signs++;}
        if (sign >= '0' && sign <= '9') {count_digits++;}
        if (sign >= 'A' && sign <= 'Z') {count_high_signs++;}
        if (sign >= 'a' && sign <= 'z') {count_low_signs++;}
        if (sign == ' ') {count_spaces++;}
    }
    printf("Number of symbols in string : %d\n", count_signs);
    printf("Number of digits in string : %d\n", count_digits);
    //printf("Percentage of digits : %f percent\n", percentage_digits);
    printf("Number of high symbols in string : %d\n", count_high_signs);
    //printf("Percentage of high symbols : %f percent\n", percentage_high_signs);
    printf("Number of low symbols in string : %d\n", count_low_signs);
    //printf("Percentage of low symbols : %f percent\n", percentage_low_signs);
    printf("Number of spaces in string is : %d", count_spaces);
    //printf("Percentage of spaces : %f percent\n", percentage_spaces);
}
void print_title(void)
{
    printf("Enter text with digits to count symbols of it : \n");
}
