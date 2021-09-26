#include <stdio.h>
#include <math.h>

int main(void)
{
    int r;                                        //Обьявление переменной ввода
    r = ++r;
    float                                         //Обьявление переменных вывода
    lc = 2*M_PI*r,
    sc = M_PI*r*r,
    vc = (4/3)*(M_PI*r*r*r);
    
    printf("Input integer radius:\n");           //Инструкция ввода переменной
    
    scanf("%d", &r);                             //Ввод переменной радиуса окружности
    
    printf("Длина окружности равна %f\n", lc);  //Вывод на экран переменных
    printf("Площадь круга равна %f\n", sc); 
    printf("Обьем шара равен %f\n", vc);

    return 0;
}