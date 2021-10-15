#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    //Обьявление переменной ввода
    int r = 0;
    //Инструкция ввода переменной
    printf("Input integer radius:\n");
    //Ввод переменной радиуса окружности
    scanf("%d", &r);
    //Обьявление переменных вывода
    float
        lc = 2*M_PI*r,
        sc = M_PI*r*r,
        vc = (4/3)*(M_PI*r*r*r);
    //Вывод на экран переменных
    printf("Длина окружности равна %.2fm\n", lc);
    printf("Площадь круга равна %.2fm^2\n", sc);
    printf("Обьем шара равен %.2fm^3\n", vc);
    return 0;
}