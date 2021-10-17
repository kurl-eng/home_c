#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//5,5(10) = 101.1
//101.1 => 1.011 * 2^2
//0 , 127 + 2^2, 011
//процесс нормализации
//0 1000 0001 01100000000000000000000

uint32_t float_as_u32(float arg);
void print_u32(uint32_t arg);

//1. Как будет хранится число 0,625 тип float
//0,625(10) = 0,101(2) => 1,01 * 2^(-1)
//0 0111 1110 01000000000000000000000

//2. Как будет хранится число 3,875 тип float
//3,875(10) = 11,111(2)
//1,1111 0000 000000000000000000000000* 2^1
//0 1000 0000 111100000000000000000000

//3. Как будет хранится число 64 тип float
//64(10) = 1000000(2)
//1,0000 0000 00000000000000000000000 * 2^6
//0 1000 0101 00000000000000000000000
//денормализация, вычисление порядка 1000 0101 = 133(10)(6 порядков)
// опускается для экономии 1 бит под хранение мантисы (1),00000000000000000000000
//1,00000000000000000000000 * 2^6 = 1000000(2) = 64(10)

//Самостоятельно
//7,625(10) = 111,101 (2)
//1,1110 1000 0000 0000000000000000000 * 2^2
//0 129(10)(1)  11101
//0 1000 0001 1110 1000000000000000000

//в скобках [] не указан размер массива,
//когда мы передаем его в функцию, инфо о размере теряется,
//т.к. запись массива преобразуется в указатель.
//поэтому мы передаем в функицию количество элементов int N,
//если мы обрабатываем массив
void enter_array(int array[], int N);
void print_array(int array[], int N);
void print_array_simple(int array[], int N);
void fill_array_random(int array[], int N);

//1. Ввести с клавиатуры массив из 5 элементов и умножить
// все его элементы на число 3. Распечатать полученный массив.
void mul_array(int array[], int N, int mult);
//3. Найти минимальный элемент в массиве.
int get_min_element(int array[], int N);
//4. Найти максимальный элемент в массиве.
int get_max_element(int array[], int N);
//5. Поменять местами максимальный и минимальный элемент в массиве.
void swap_min_max(int array[], int N);
//6. На стандартном потоке ввода задан текст, состоящий из латинских букв и
//цифр и оканчивающийся точкой. На стандартный поток вывода вывести
//цифру, наиболее часто встречающуюся в тексте (если таких цифр несколько,
//вывести любую из них).
void print_max_freq_dig(void);
//7. Циклически сдвинуть массив влево на 1 элемент.
// 1 2 3 4 5 >> 2 3 4 5 1
void shift_left_array(int array[], int N);
// 1 2 3 4 5 << 5 1 2 3 4
void shift_right_array(int array[], int N);
//Сделать реверс массива
// 1 2 3 4 5 <<>> 5 4 3 2 1
void swap(int *a, int *b);
void reverse_array(int array[], int N);

int main(void)
{
    printf("\n");

    //для изменения количества элементов массива,
    //объявим переменнную аргументов массива
    //int N = 5;
    //int array[N];
    //enter_array(array, N);
    //print_array(array, N);

    //mul_array(array, N, 3);
    /*fill_array_random(array, N);
    print_array(array, N);
    printf("Minimum %d\n", get_min_element(array, N));
    printf("Maximum %d\n", get_max_element(array, N));
    swap_min_max(array, N);
    print_array(array, N);*/

    /*int *p_array = &array[0];
    p_array[0] = 10;
    array[0] = 10;
    array[4] = 25;
    array[9] = 124;
    */

    //float x = 732423423.6435345435625f;
    /*float x = 0.1f;
    for (int i = 0; i < 10; i++) {
        print_u32(float_as_u32(x));
        //так не делают
        if (x == 1.f) {
            printf("Equils 1.f\n");
        }
        //Equils 0.000001f or less
        if (fabs(x - 1.f) < 0.000001f) {
            printf("Equils DELTA 1.f\n");
        }

        x += 0.1f;
    }
    print_u32(float_as_u32(1.f));
    printf("%f\n", x);
*/

    /*
    print_u32(float_as_u32(7.625f));
    print_u32(float_as_u32(7.625f));
    print_u32(float_as_u32(64.f));
    print_u32(float_as_u32(3.875f));
    print_u32(float_as_u32(0.625f));
*/
    //printf("\n");
    //print_u32(float_as_u32(x));
    /*print_u32(float_as_u32(0.f));
    print_u32(float_as_u32(1.f));
    print_u32(float_as_u32(5.5f));
    print_u32(float_as_u32(-5.5f));*/

    //print_max_freq_dig();

    int array[5] = { 0 };
    //enter_array(array, 5);
    fill_array_random(array, 5);
    print_array_simple(array, 5);
    shift_left_array(array, 5);
    print_array_simple(array, 5);
    shift_right_array(array, 5);
    print_array_simple(array, 5);
    reverse_array(array, 5);
    print_array_simple(array, 5);
    printf("\n");
    return 0;
}

void reverse_array(int array[], int N)
{
    for (int i = 0; i < (N / 2); i++) {
        swap(&array[i], &array[N - i - 1]);
    }
}

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void shift_right_array(int array[], int N)
{
    int tmp = array[N - 1];
    for (int i = N - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = tmp;
}

void shift_left_array(int array[], int N)
{
    int tmp = array[0];
    for (int i = 1; i < N; i++) {
        array[i - 1] = array[i];
    }
    array[N - 1] = tmp;
}

void print_max_freq_dig(void)
{
    char ch;
    int array[10] = { 0 };

    while((ch = getchar()) != '.') {
        if (ch >= '0' && ch <= '9') {
            array[ch - '0']++;
        }
    }
    int max_index = 0;
    int max = array[0];
    for (int i = 0; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }
    //%d, max_index
    printf("most frequently digit is %c\n", ('0' + max_index));
}

void swap_min_max(int array[], int N)
{
    int min = array[0], max = array[0];
    int min_index = 0, max_index = 0;
    int tmp;

    for (int i = 0; i < N; i++) {
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }
    tmp = array[max_index];
    array[max_index] = array[min_index];
    array[min_index] = tmp;
}

int get_max_element(int array[], int N)
{
    int max = array[0];
    for (int i = 0; i < N; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}



int get_min_element(int array[], int N)
{
    int min = array[0];
    for (int i = 0; i < N; i++) {
        if (array[i] < min)
        min = array[i];
    }
    return min;
}

void mul_array(int array[], int N, int mult)
{
    for (int i = 0; i < N; i++) {
        array[i] *= mult;
    }
}

void fill_array_random(int array[], int N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100 - 50;
    }
}

void print_array_simple(int array[], int N) 
{
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");
}

void print_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("ptr %p array[%d] = %d\n", &array[i], i, array[i]);
    }
}

void enter_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
}

void print_u32(uint32_t arg)
{
    //устанавливаем цикл на 32 итерации
    for (int i = 31; i >= 0; i--) {
        //форматируем вывод для float IEEE754
        if (i == 30 || i == 22) {
            putchar(' ');
        }
        //маскирование аргумента для смещения оператора
        if ((arg >> i) & 0x1) {
            putchar('1');   
        } else {
            putchar('0');
        }
    }
    printf("\n");
}

uint32_t float_as_u32(float arg)
{
    uint32_t result = 0;
    //куда, откуда, сколько байт
    memcpy(&result, &arg, 4);
    printf("float %f = ", arg);
    return result;
}