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
        if (sign >= '0' && sign <= '9'){
            counter_numbers += sign - '0';
        } else if (sign >= 'A' && sign <= 'Z'){
            counter_high_letters += sign - 'A';
        } else if (sign >= 'a' && sign <= 'z'){
            counter_low_letters += sign - 'a';
        } else if (counter_spaces == ' '){
            counter_spaces += sign - ' ';
        }
        putchar(counter_numbers); 
    }
    printf("Summary %d symbols of number,\n", counter_numbers);
    printf("%d upper symbols,\n", counter_high_letters);
    printf("%d lower symbols,\n", counter_low_letters);
    printf("and %d number of spaces: ", counter_spaces);
}

int main(void)
{
    printf("Enter text with digits to count symbols of it: \n");
    
    get_string_summary();

    return 0;
}