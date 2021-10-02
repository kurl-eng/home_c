#include <stdio.h>
#include <stdbool.h>

int main (void)
{
unsigned int i, j, n;
bool is_prime;

    for (i = 2; i < n; i++)
    {
    is_prime = 1;
    for (j = 2; j * j <= i; j++) //j <= sqrt(j)
        if (i % j == 0)
        {
            is_prime = 0;
            break; //exit
        }
    if (is_prime)
        printf("%u", i);
    }
}