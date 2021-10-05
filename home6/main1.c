#include <stdio.h>

void print_title(void);

//void high_absolute(void);

//void lenght_absolute(void);

int main(void)
{
    print_title();
    absolute_sign_counter();
    //high_absolute();
    //int value = 0;
    //value = get_string();

    //print_count();
    //lenght_absolute();

    return 0;
}

void absolute_sign_counter(void)
{
    char sign = getchar();
    int high_count, low_count, number_count;
    for (sign >= 'A' && sign <= 'Z'; high_count <= sign ; high_count++)
    {
        printf("Number of upper symbols : %d\n", &high_count);
    }
    return 0;
}

/*void high_absolute(void)
{
    char sign;
    int count = 0;

    while((sign = getchar()) != '\n'){
        for (sign >= 'A' && sign <= 'Z'; count <= sign; count++);
    }
    printf("Number of upper symbols : %d\n", &count);
}*/

/*void lenght_absolute(void)
{
    char sign;
    int sum = 0;

    while ((sign = getchar()) != '\n')
    {
        if (sign >= 'a' && sign <= '0')
        {
            sum += sign - '0';
        }
    }
    printf("Total lenght of string is: %d", &sum, " symbols");
}*/

void print_title(void)
{
    printf("Enter text with digits to count symbols of it: \n");
}
