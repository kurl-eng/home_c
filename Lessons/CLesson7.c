#include <stdio.h>

void test(void);

void swap(int a, int b);

int main(void)
{
    /*test();
    test();
    test();*/

    int a = 5, b = 10;
    
    printf("%d %d\n", a, b);
    swap(a, b);
    printf("%d %d\n", a, b);
    return 0;
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}



void test(void)
{
    //модификатор static сохраняет результаты переменной при выходе из функции
    static int a = 5;
    a++;
    printf("%d\n", a);
}