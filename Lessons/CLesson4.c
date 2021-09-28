//подключение заголовочных файлов библиотек макросов
//для определения пользовательских типов
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

//объявление основной функции
int main(void)
{
    float radius;
    int ret;
    //возвращение количества успешных преобразований через ret
    ret = scanf("%f", &radius);
    printf("ret %d radius = %.2f\n", ret, radius);
    //для проверки валидности вводных данных обозначим цикл
    if ((ret == 1) && (radius >= 0.f))
    {
        printf("Radius = %.2f\n", radius);
        //some code expr == true
    }
    else
    { // или просто else if (ret == 0)
        printf("error!\n");
        //some code if expr == false
    }

    return 0;

    /*
    int a = 25;
    int b = 0;
    // ! && ||
    //a = !a;
    //приведение численного значения к логическому
    int result = a || b;

    printf("result = %d\n", result);
    */

    /*
    uint8_t c;
    scanf("%u", &c);
    printf("Hi\nInputed %" PRIu8 "\n", c);
    */

    //uint32_t c;
    //"%"" спецификатор для изменеия режима ввода строки
    //"%u" спецификатор для изменения ввода символа на беззнаковый
    //"%" PRIu32, беззнаковый спецификатор 32 разрядов
    //& спецификатор ввода переменной в память (присваивает адрес)
    //for help type where is inttypes.h
    //scanf("%" PRIu32, &c);
    //printf("Hi\nInputed %" PRIu32 "\n", c);

    /*
    //объявление знаковой целочисленной переменной
    int a;
    //объявление знаковой целочисленной переменной 32 разряда
    int32_t b;
    ////объявление беззнаковой целочисленной переменной 8 разрядов
    uint8_t c;
    */
}