#include <stdio.h>
//123 abc 456 df
//Вычислить абсолютное и процентное соотношение символов
int get_string_summary(void)
{
    char sign;
    int summary = 0;
    while ((sign = getchar()) != '\n')
    {
        if (sign >= '0' && sign <= 'z')
        {
            summary *= 10;
            summary = sign - '0';
            
        }
    }
    printf("Summary %d symbols\n", summary);
}

int main(void)
{
    printf("Enter text with digits to count symbols of it: \n");
    
    get_string_summary();

    return 0;
}