#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// == != < > ; ++ -- ; + a , - a; ptr - ptr2

void fill_array(int array[], int N)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100 - 50;
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

void print_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("[%d] = %d ptr=%p\n", i, array[i], N);
    }
}

int main(void)
{
    int array[5] = { 0 };

    fill_array(array, 5);
    print_array(array, 5);

    int *p_array = &array[0];

    return 0;
}