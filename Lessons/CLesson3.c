#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    int x1, x2, x3;
    int y1, y2, y3;
    float res; //в неициализированной переменной мусор
    printf("Enter x1, x2, x3 :\n");
    scanf("%d%d%d", &x1, &x2, &x3);
    y1 = x1 + x2 + x3; //инициализация y
    y2 = x1 * x2 * x3;
    res = (float)(x1 + x2 + x3) / 3.f;
    printf("%d + %d + %d = %d\n", x1, x2, x3, y1);
    printf("%d * %d * %d = %d\n", x1, x2, x3, y2);
    printf("(%d + %d + %d) / 3 = %.2f\n", x1, x2, x3, res);

    /*
    int x1, x2, x3;
    int y; //в неициализированной переменной мусор
    printf("Enter x1, x2, x3 :\n");
    scanf("%d%d%d", &x1, &x2, &x3);
    y = x1 + x2 + x3; //инициализация y
    printf("%d + %d + %d = %d\n", x1, x2, x3, y);
    */

    /*
    int seconds = 12334;
    int hours = seconds / 60 / 60;
    int minutes = seconds % 3600 / 60;

    printf("Hours : %d Minutes %d\n", hours, minutes);
    */

    /*
    float f1 = 123.64;
    int k, fint;

    fint = f1; //переведем число float в int
    fint *= 10; // сдвинем на разряд
    f1 *= 10; // сдвинем на разряд
    k = f1 - fint; //получим разницу в разряде

    printf("result %d\n", k);
    */

    /*
    int x = 123;
    int k = 0;

    k += x % 10; //k = k(0) + 12 3% 0 = 3
    x /= 10; // 123 / 10 = 12 = x
    k += x % 10; // k = 0 + 12 % 10 = 2
    x /= 10; //12 / 10 = 1 = x
    k += x; // k = 1 //k+= x % 10;

    printf("result %d\n", k);
    */

    /*
    int k;
    int x = 123456;

    k = x / 100;

    k = k % 10;

    printf("2nd range number is %d\n", k);
    */

    return 0;
}