//подключение заголовочных файлов библиотек макросов
//для определения пользовательских типов
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

//объявление основной функции
int main(void)
{

    return 0;
}

//Инвертировать 5 младших битов переменной x типа unsigned int,
//остальные биты оставить без изменения.
/*
    unsigned int mask, n = 0xAB; // n = 1010 1011
    mask = (1 << 5) - 1;
    n = n ^ mask;
    printf("n = %x %x\n", n, mask);
*/

/* 
    int a = 10, b = 20, tmp;
    tmp = a;
    a = b;
    b = tmp;
    */
//Не используя дополнительных переменных,
//поменять местами значения двухпеременных типа int.
//int a = 10, b = 20;
//арифметически
/*
    a = a + b; // или так
    b = b - a; //b = a - b;
    b = - b;   // лишняя операция
    a = a - b;
    */
//логически
/*
    a ^= b;
    b ^= a;
    a ^= b;
    */
//printf("result a = %d b = %d\n", a, b);

/* «Распаковать» беззнаковое целое число в четыре символа.
    Размербеззнакового целого - 4 байта.return 0; */
/*
    unsigned int n = 0xaabbccdd;
    unsigned char a, b, c, d, e;
        
    d = n;
    c = n >> 8;
    b = n >> 16;
    a = n >> 24;
    printf("a = %x, b = %x, c = %x, d = %x\n", a, b, c, d);
    printf("0xe =%x%x%x%x\n", a, b, c, d);
    */

/* «Упаковать» четыре символа в беззнаковое целое.
    Размер беззнаковогоцелого - 4 байта.return 0; */
// n = aabbccdd
/*
    unsigned int n = 0;
    //Обозначим беззнаковое 16ое представление переменных
    //через спецификатор 0x
    unsigned char a = 0xaa, b = 0xbb, c = 0xcc, d = 0xdd;

    n = a;
    n = n << 8; //0xaa00
    n |= b;     //0xaabb
    n = n << 8; //0xaabb00
    n |= c;     //0xaabbcc
    n = n << 8; //0xaabbcc00
    n |= d;     //0xaabbccdd

    //выведем запакованное число через спецификатор %x
    printf("0x%x\n", n); 
*/

//Поднять два младших бита в 4 байтном беззнаковом числе.
// 1000 в 1011
//unsigned int a = 0xFFFFFF00;
//printf("result %x\n", a | 0x3); //or a | 3

//Переменная имеет тип unsigned int,
//необходимо обнулить 3 младших битачисла.
//1000
//unsigned int a = 0xAABBCCFF;
//unsigned int mask = 0xFFFFFFF8;
/*
    a = a >> 3;
    a = a << 3;
    printf("%x\n", a);
    */
//printf("%x\n", a & mask);

//int a, b;
//scanf("%d%d", &a, &b);
/*
    if (a > b) {
        printf("max = %d\n", a);
    } else {
        printf("max = %d\n", b);
    }
    */
//запишем ветвление с помощью тринарного оператора
//printf((a > b) ? "a = %d" : "b = %d", (a > b) ? a : b);
//printf("max %d", (a > b) ? a : b);

/*
    int arg;
    int result;

    scanf("%d", &arg);

        
    //if (arg > 0) {
    //    result = pow(arg, 2);
    //} else {
    //    result = 0;
    //}
   

    //       (условие) ?    истина   : ложь
    result = (arg > 0) ? pow(arg, 2) : 0;
    printf("result %d\n", result);
    */

/*
    scanf("%d", &arg);

    if (arg == 1) {
        printf("ONE\n");
    } else if (arg == 2) {
        printf("TWO\n");
    } else if (arg == 3) {
        printf("THREE\n");
    } else {
        printf("MORE THAN THREE\n");
    }
    */

/*
    float radius;
    int ret;
    //возвращение количества успешных преобразований через ret
    ret = scanf("%f", &radius); 
    printf("ret %d radius = %.2f\n", ret, radius);
    //для проверки валидности вводных данных обозначим цикл
    if ((ret == 1) && (radius >= 0.f)) {
        printf("Radius = %.2f\n", radius);
        //some code expr == true
    } else { // или просто else if (ret == 0)
        printf("error!\n");
        //some code if expr == false
    }
    */

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