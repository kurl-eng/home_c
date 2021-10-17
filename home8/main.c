#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int print_title(int *N);

//случайный массив от -50 до 50
void rand_array(int array[], int N);

//вывод массива
void print_array(int array[], int N);

//сравниваем элементы массива
int bubble_array(int array[], int N);

//вывод упорядоченного массива
void print_sorted_array(int array[], int N);

int main(void)
{
    int N = print_title(&N), array[N];
    rand_array(array, N);
    print_array(array, N);
    bubble_array(array, N);
    print_sorted_array(array, N);

    printf("\n");
}

void print_sorted_array(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf(" [%d] = %d |", i, array[i]);
    }
    printf("\n");
}

int bubble_array(int *array, int N)
{
    //проход по массиву N элементов i элементов
    for (int i = 0; i < N; i++) {
        //проход по массиву N для Z элементов
        for (int Z = (N - 1); Z > i; Z--) {
            //для текущего Z < предыдущего Z
            if (array[Z - 1] > array[Z]) {
                //меняем элементы местами
                int swap = array[Z - 1];
                array[Z - 1] = array[Z];
                array[Z] = swap;
            }
        }
    }
}

void print_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        printf(" [%d] = %d |", i, array[i]);
    }
    printf("\n");
}

void rand_array(int array[], int N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100 - 50;
    }
}

int print_title(int *N)
{
    printf("Enter array range\n");
    scanf("%d", N);
    return *N;
}