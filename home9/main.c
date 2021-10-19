#include <stdio.h>
#include <stdbool.h>

//получим строку для определения значений и операций
char get_input(char *string);

//условие если знак это цифра
bool is_number(char sign);

//переведем строковые выражния в числовые операции
float number_container(void);

char main()
{
    //char string;
    //get_input(&string);
    number_container();
    printf("\n");
    return 0;
}

float number_container(void)
{
    //значение строки для сравнения с числом
    char string;
    //индекс числа
    int digit_index;
    //длина массива
    int range = 0;
    //массив для хранения строк в виде чисел
    //с операцией перед ним из get_input
    int number_array[range];
    //признак сложения
    bool cross = false;
    //признак вычитания
    bool negative = false;
    //признак деления
    bool divider = false;
    //признак умножения
    bool multiplier = false;
    
    while (get_input(&string) == is_number(string)) {
        for (range; range < digit_index; range++) {
            number_array[digit_index++];
            putchar(number_array[digit_index]);
        }
    }
}

bool is_number(char sign)
{
    return(sign >= '0' && sign <= '9') ? true : false;
}

char get_input(char *string)
{
    printf("enter math expression to calculate it : \n");
    while ((*string = getchar()) != '\n')
        putchar(*string);
        return *string;
}