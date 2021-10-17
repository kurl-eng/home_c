#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//floating point exepction
//float x = 123.45; 
//у float не понятия как остаток от деления
//т.к. остаток от деления это целочисленная операция
//float result = x % 10.f;

//разбор ДЗ6 со *
//for float ctr-f and change float to double
/*bool is_num(char ch)
{
    return(ch >= '0' && ch <= '9') ? true : false;
}

float get_float(void)
{
    float result;
    char ch;
    //признак отрицательного числа
    bool negative = false;
    //признак точки или запятой
    bool divider = false;
    //переменные хранящие целую и дробную часть
    float first = 0, second = 0; 

    while ((ch = getchar()) != '\n') {
        if (ch == '-') {
        negative = true;
        continue;
        }
        if (ch == '.' || ch == ',') {
        divider = true;
        continue;
        }
        if (is_num(ch)) {
            if (divider) {
            second *= 10;
            second += ch - '0';
            } else {
            first *= 10;
            first += ch - '0';
            }
        }

    }

    int tmp;

    while (tmp = second) {
        second /= 10;
    }

    result = first + second;
    if (negative) {
        result *= -1;
    }

    printf("first %f second %f\n", first, second);

    return result;
}

int main(void)
{
    float test = get_float();
    printf("you've entered %f\n", test);
    return 0;
}
*/

//creating Makefile
//sudo apt install make
//

//передаем массив в функцию и для вывода значений рандом
//массив не явно преобразован в указатель идентичный массиву fill_array2
//void fill_array(int array[], int N);
void fill_array(int *array, int N);

//операции с указателями массивва
// == != < > ; ++ -- ; + a , - a; ptr - ptr2
//void fill_array2(int *array, int N);

void print_array(int *array, int N);

/*1.1 Написать функцию вычисления скалярного произведения 
      двух вещественных массивов. */
//отметим оператором const указатели входных параметров для удобства
void scalar_mult(const float array1[], const float array2[], float result[], int N);
void scalar_mult_ptrs(const float *array1, const float *array2, float *result, int N);
//допишем функцию вывода
void print_array_float(const float *array, int N);

/*1.2 Составить функцию которая определяет в массиве, состоящем из
положительных и отрицательных чисел, сколько элементов превосходят по
модулю максимальный элемент. Показать пример ее работы на массиве из 10
элементов. */
int int_module(int arg);
int get_mod_max_amount(int *array, int N);

//напишем функцию аналогичную функии strlen библиотеки string.h
int my_strlen(const char *str);
int get_string(char *str);

int main(void)
{
    //объявление массива с инициализацией 0-ми
    //int array[5] = { 0, 10, 20, 30, 60 };
    //print_array(array, 5);

    //чтобы определить размер массива, вычтем последний адрес из первого
    //int *p_0 = &array[0], *p_4 = &array[4];
    //printf("adresses diff %d\n", p_4 - p_0);

    //размер массива / sizeof(int) будет размером адреса ячейки
    //printf("sizeof array %lu\n", sizeof(array));

    //fill_array(array, 5);

    /*//указываем переменной на первый элемент массива явным образом
    //присвоение определенного адреса массива указателю
    int *p_array = &array[4];
    //аналогично можно изменить адресс массива для вывода без арифметики указателей
    //через printf("V1 %d", p_array[0]);
    printf("V1 %d ptr %p", *p_array, p_array);
    printf("\n");
    p_array -= 1; //p_array + 1 (p_array ++;)
    //можно изменить значение адреса при следующем проходе
    *p_array = 222;
    //printf("V1 %d", p_array[4]);
    printf("V2 %d ptr %p", *p_array, p_array);
    //как видно адрес увеличился на значение элемента индекса
    //print_array(p_array, 5);*/

    /*1.1 float array1[5] = {0.f, 10.f, 20.f, 30.f, 60.f};
    float array2[5] = {123.f, 15.f, -4.f, -1.f, 3.f};
    float result[5] = { 0.f };
    scalar_mult_ptrs(array1, array2, result, 5);
    print_array_float(array1, 5);
    print_array_float(array2, 5);
    print_array_float(result, 5);*/

    /*1.2 int array[10];
    fill_array(array, 10);
    print_array(array, 10);
    printf("get_mod_max_amount = %d\n", get_mod_max_amount(array, 10));
    */

    //в каждой строке есть последний(нулевой) неявный символ \0,
    //поэтому для хранения 10 символов нужен массив из 11 адресов
    //char str[11] = "1234567890";
    //аналогичная запись массива для 10 символов с инициализацией
    //char str[11] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'};
    //указатель на первый символ
    //char *str = "1234567890";

    char str[100] = { 0 };

    int count = get_string(str);
    printf("sizeof %lu strlen %d\n", sizeof(str), my_strlen(str));
    printf("entered string : %s\n", str);

    /*scanf("%s", str);
    printf("%s\n", str);
    printf("sizeof %lu strlen %d", sizeof(str), my_strlen(str));
    */

    printf("\n");
    return 0;
}

int get_string(char *str)
{
    int ctr = 0;
    char ch;

    while ((ch = getchar()) != '\n' ) {
        *str++ = ch;
        ctr++;
    }
}

int my_strlen(const char *str)
{
    int size = 0;
    while (*str++) {
        size++;
    }
    return size;
}

int get_mod_max_amount(int *array, int N)
{
    int max_mod_amount = 0;
    //определение максимального элемента массива
    int max = array[0];
    for (int i = 0; i < N; i++) {
        if (array[i] > max) 
            max = array[i];
    }
    printf("max element %d\n", max);
    for (int i = 0; i < N; i++) {
        if (int_module(array[i]) > max) 
            max_mod_amount++;
    }
    return max_mod_amount;
}

int int_module(int arg)
{
    return (arg < 0) ? -arg : arg;
}

void print_array_float(const float *array, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("[%d] = %f ptr=%p\n", i, *(array + i), (array + i));
    }
}

void scalar_mult_ptrs(const float *array1, const float *array2, float *result, int N)
{
    for (int i = 0; i < N; i++) {
        *(result + i) = *(array1 + i) * *(array2 + i);
    }
}

void scalar_mult(const float array1[], const float array2[], float result[], int N)
{
    for (int i = 0; i < N; i++) {
        result[i] = array1[i] * array2[i];
    }
}

void print_array(int *array, int N)
{
    for (int i = 0; i < N; i++)
    {
        //printf("[%d] = %d ptr=%p\n", i, array[i], &array[i]);
        printf("[%d] = %d ptr=%p\n", i, *(array + i), (array + i));
    }
}

void fill_array2(int *array, int N)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        *(array + i) = rand() % 100 - 50;
    }
}

void fill_array(int *array, int N)
{
    //размер указателя
    //printf("sizeof array %lu\n", sizeof(*array));
    //return;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100 - 50;
    }
}
