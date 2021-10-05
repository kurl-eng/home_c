#include <stdio.h>
//123 abc 456 df
//Вычислить абсолютное и процентное соотношение символов
int get_string_summary(void)
{
    char sign;
    int
        counter_numbers = 0,
        counter_high_letters = 0,
        counter_low_letters = 0,
        counter_spaces = 0;

    while ((sign = getchar()) != '\n'){
        if (sign == ' ') {
            counter_spaces += counter_spaces;
        }
    printf("Summary %d symbols\n", counter_spaces);
    }
}

int main(void)
{
    printf("Enter text with digits to count symbols of it: \n");
    
    get_string_summary();

    return 0;
}