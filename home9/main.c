#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//даем ползовтелю инструкцию для ввода данных
char input(char *string);
//массив строки из input
float expr_array(char string[], int range);
//печатаем массив
char print_array(char string[], int range);

void main(void)
{
    //int digit;
    //переменная длины массива
    int range;
    //передаем строку в в перменную массива
    char string[range];
    //функция ввода выражения
    input(string);
    /* передаем строку в переменную int
       функцией подсчета символов */
    range = strlen(string);
    print_array(string, range);
    printf("array[%s]\n", string);
    expr_array(string, range);
    printf("array[%s]\n", string);
}

bool is_num(char sign)
{
    return (sign >= '0' && sign <= '9') ? true : false;
}

char print_array(char string[], int range)
{
    for (int i = 0; i < range; i++) {
        printf("array[%d] = %c\n", i, string[i]);
    }
}

float expr_array(char string[], int range)
{
    float digit;
    //признак точки или запятой
    bool f_val = false;
    //признак сложения
    bool cross = false;
    //признак вычитания чисел
    bool negative = false;
    //признак делителя
    bool divider = false;
    //признак умножения
    bool multiplier = false;
    //переменные хранящие целое и остаток
    float integer = 0, remain = 0;
    //проход по массиву с последнего элемента
    //for (int sign = range; sign != 0; sign--)
    //проход по массиву с 0-го элемента
    for (int sign = 0; sign < range; sign++) {
        //логический проход пока символ цифра
        is_num(string[sign]);
        //while (string[sign] >= '0' && string[sign] <= '9') 
        //идём док конца массива
        while (true == EOF) {
            //видим признак вещественного цисла
            if (sign == '.' || ',') {
                //подтверждаем логически
                f_val = true;
                //продолжаем работу цикла while
                continue;
            }
            //смотрим следующее число ?++ пока в массиве символы цифр
            if (is_num(string[sign++])) {
                //запуская цикл для преобразования символов в вещественное
                if (f_val) {
                    //перевод символа в число
                    //умножаем на систему счисления
                    remain *= 10;
                    //остаток прибавляем к символу числа минус символ 0
                    remain += sign - '0';
                } else {
                    //преобразуем целую часть
                    integer *=10;
                    integer += sign - '0';
                }
            }
            //возвращаем вещественное число
            int temp;
            //переводим остаток в дробную часть
            while (temp = remain) {
                remain /= 10;
            }
            //получаем число в виде float
            digit = integer + remain;
            return digit;
            continue;
            //ищем в массиве признак сложения
            if (sign == '+') {
                cross = true;
                continue;
                //пройдем по масиву вперед
                for (int sign = 0; sign < range; sign++) {
                    if (cross == true) {
                        continue;
                        for (int Z = (range + 1); Z > sign; Z++) {
                            while (is_num(string[sign++]));
                            //дальше я вообще не понимаю потому что
                            //неправильно сделал предыдущие блоки
                        }
                    }
                }
            }

        }

    }
    
}
    

char input(char *string)
{
    printf("enter math expression to calculate it\n");
    printf("PLEASE USE CORRECT SYMBOLS (* / - +)\n");
    printf("without round brackets and spaces\n");
    //printf("works with integers only : ");
    scanf("%s", string);
    return *string;
}
