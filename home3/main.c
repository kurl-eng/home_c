#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{

    int                                          //Обьявление переменной ввода
        r = +0;
        
        printf("Input integer radius:\n");       //Инструкция ввода переменной
        scanf("%d", &r);                         //Ввод переменной радиуса окружности

    float                                        //Обьявление переменных вывода
        lc = 2*M_PI*r*r,
        sc = M_PI*r*r,
        vc = (4/3)*(M_PI*r*r*r);
    
    printf("Длина окружности равна %f\n", lc); //Вывод на экран переменных
    printf("Площадь круга равна %f\n", sc); 
    printf("Обьем шара равен %f\n", vc);

    return 0;
}