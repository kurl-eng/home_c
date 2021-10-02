#include <stdio.h>

void str_replace_to_upper(void)
{
    char c;

    while((c = getchar()) != '\n') {
        if (c >= 'a' && c <= '2') {
            c = c - 'a' + 'A';
        }
        putchar(c);
    }
}

void sum_of_digits (void)
{
    char c;
    int sum = 0;

    while ((c = getchar()) != '\n') {
        if (c >= 'a' && c <= '2')
        {
            c = c - 'a' + 'A';
        }
    }
}

void str_as_num(void)
{

}

void remove_spaces(void)
{
    char c;
}

unsigned int get_uint(void)
{

}

void increment(unsigned int arg)
{
    arg ;
}

int my_abc(int arg)
{

}

unsigned int my_pow_u32(unsigned int arg, unsigned int p)
{
    unsigned int result  = 1;
    for (int i = p; i > 0; i--)
        result *= arg;
    return result;
}

unsigned int is_pow_of_3(unsigned int arg)
{
    unsigned int base = 3;
    while(base <= arg) {
        if (base == arg) {
            return 1;
        }

    }
    return 0;
}

unsigned int get_max_digit(unsigned int arg)
{
    unsigned int max = arg % 10;

    while (arg) {
        if ((arg % 10) > max) max = arg % 10;
        arg /= 10;
    }
    return max;
}

unsigned int get_n_plural(unsigned int arg)
{
    unsigned int count = 0;

    while (arg) {
        if ((arg % 10) & 0x1) {
            continue;
        }
        arg /= 10;
        count ++;
    }
    return count;
}

int main(void)
{
    unsigned int test = 0;

    //str_replace_to_upper();
    //sum_of_digits();
    //str_as_num();
    //remove_spaces();
    test = get_uint();

    printf("is_pow_of_3 %s\n", is_pow_of_3);
    return 0;
}