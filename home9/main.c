#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* даем ползовтелю инструкцию для ввода данных */
//char input(char *string);

/* вывод массива чисел */
void print_operands(int *op, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", op[i]);
    }
    printf("\n");
}

/* вывод массива операций */
void print_operations(char *op, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%c ", op[i]);
    }
    printf("\n");
}

/* вывод массива символов из строки */
//char print_array(char string[], int range);

void main(void)
{
    // строка для примера
    const char *string = "(100+200+300)/5";

    /* переменная длины массива, числа и операции */
    int range, number = 0, operation = 0;
    /* передаем строку в массив чисел */
    int numbers[100] = { 0 };
    /* передаем строку в массив операций */
    int operations[100] = { 0 };
    /* передаем строку в перменную массива */
    //char string[range];
    /* функция ввода выражения*/ 
    //input(string);
    /* передаем строку в переменную int
       функцией подсчета символов для
       определения длины масссива */
    //range = strlen(string);
    //print_array(string, range);
    //printf("array[%s]\n", string);

    /* проход по массиву для определения чисел и операций */
    for (int i = 0; i <= strlen(string); i++) {
        /* присваиваем текущий символ элемента массива */
        char sign = string[i];
        /* условие определения числа */
        if ( sign >= '0' && sign <= '9') {
            /* для перевод элементов массива в числа
            умножаем символ на систему счисления */
            numbers[number] *= 10;
            /* складываем числовое значение каждого элемента
             массива и отнимаем значения символа '0' из таблицы */
            numbers[number] += sign - '0';
        }
        /* условие определения операции над числом */
        if (sign == '+' || sign == '-' || sign == '*' || sign == '/') {
                /* идем к следующиему элементу из массива чисел */
                number++;
                /* наполняем массив символов операций
                значениями массива string */
                operations[operation] = sign;
                /* идем к следующему элемету из массива операций */
                operation++;
            }
    }
    /* условие определения правильности выражения */
    if (operation == number) {
        /* мне не очень понятно */
        number++;
    }
    /* вывод полученых значений массивов */
    //print_operands(numbers, number);
    //print_operations(operations, operation);
    // не перевел строчный массив в числовой

    /* так как первое число начинает счёт слева направо
       объявим переменную результата вычисления значений
       первым элементом массива чисел */ 
    int result = numbers[0];
    /* условие выполнения операций между массивами*/
    for (int i = 0; i < operation; i++) {
        /* определим условие операторов */
        switch (operations[i]) {
            /* если символ массива операций +, то запишем в результат 
               операцию сложения текущего и следующего числа массива */
            case '+' : result += numbers[i + 1];
            break;
            /* действие над  предыдущим результатом 
               при другом значении массива операций */
            case '-' : result -= numbers[i +1];
            break;
            case '*' : result *= numbers[i + 1];
            break;
            case '/' : result /= numbers[i + 1];
            break;
        }
    }
    /* вовод */
    printf("operaton %d number %d\n", operation, number);
    /* вывод результата вычисления */
    printf("result %d\n", result);

}

/*char print_array(char string[], int range)
{
    for (int i = 0; i < range; i++) {
        printf("symbol of string array [%d] = %c\n", i, string[i]);
    }
}*/

/*char input(char *string)
{
    printf("enter math expression to calculate it\n");
    printf("PLEASE USE CORRECT SYMBOLS (* / - +)\n");
    printf("without round brackets and spaces\n");
    printf("works with integers only : ");
    scanf("%s", string);
    return *string;
}*/
