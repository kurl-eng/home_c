#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void enter_array(int array[], int N);
void print_array(int array[], int N);

int main(void)
{
    printf("\n");
    int range;
    int array[range];
    enter_array(array, range);
    print_array(array, range);
}

void enter_array(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("ptr %p array[%d] = %d\n", &array[i], i, array[i]);
    }
}
