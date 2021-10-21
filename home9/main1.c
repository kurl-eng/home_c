#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool get_user_input_int(int *a, int *b)
{
    int retcode;
    retcode = scanf("%d%d", a, b);
    if (retcode == 2) {
        return true;
    } else {
        return false;
    }
}

char get_input(char string[], int range);
//входной массив выражения
char enter_array(char string[], int range);
//вывод массива выражения
char out_array(char string[], int range);

void menu_ifelse(int arg);
void menu_switch(int arg);

void print_digits_num(int arg);



void print_digits_summ(int arg);

void print_natur_dividers(int arg);

void print_n_squares(int N);

bool is_prime(int arg);

char get_user_input(char string);

float sum_of_dig(float sum);

float str_as_expr(float string);
void remove_spaces(void);

unsigned int is_pow_of_3(unsigned int arg)
{
    unsigned int base = 3;
    while (base <= arg) {
        if (base == arg) {
            return 1;
        }
        base *= 3;
    }
    return 0;
}

int my_abs(int arg)
{
    return (arg < 0) ? - arg : arg;
}

unsigned int my_pow_u32(unsigned int arg, unsigned int p)
{
    unsigned int result = 1;
    for (int i = p; i > 0; i--)
    //result *= arg;
    return result;
}

unsigned int get_max_digit(unsigned int arg)
{
    unsigned int max = arg % 10;

    while (arg) {
        if ((arg % 10) > max)
            max = arg % 10;
            arg /= 10;
    }
    return max;
}

/*получаем со стандартного потока ввода через getchar 
unsigned int*/
unsigned int get_uint(void);
unsigned int increment(unsigned int arg)
{
    //unsigned int arg = main:test;
    //значение снаружи передано внутрь для вычисления и возврата
    arg += arg;
    printf("Increment : %u\n", arg);
    return arg;
}

unsigned int digit_summary(unsigned int n)
{
    if (n <= 9)
    {
        return n;
    }

    return (n % 10) + digit_summary(n / 10);
}

int main(void)
{

    
    /*
    int from_user = get_user_input();
    printf("number %d is prime %s\n", from_user, is_prime(from_user) ? "TRUE" : "FALSE");

    for (int i = 1; i <= from_user; i++)
    {
        printf("Iteration %d of %d\n", i, from_user);
    }

    int i = 1;
    while (i <= from_user) {
        printf("Iter %d of %d\n", i, from_user);
        i++;
    }

    menu_ifelse(from_user);
    menu_switch(from_user);
    print_digits_num(from_user);
    print_digits_summ(from_user);
    print_natur_dividers(from_user);
    //print_n_squares(from_user);
    int delim = 5;
   
    while ((from_user != 0) && (from_user <= 3))
    {
        printf("HomeWork #9\n");
        from_user--;
    }

    printf("func result %d\n", from_user);
    */

    /*
    int range;
    char string, expr;
    expr = get_user_input(string);
    */

    /*while ((c = getchar()) != '\n') {
    putchar(c);
    }*/
    
    /*
    str_as_expr(expr);
    sum_of_dig(expr);
    */
/*
   int a = 5, b = 10;

   bool ret = get_user_input_int(&a, &b);
   if (ret == false) {
       printf("Error\n");
       return -1;
   }
   printf("%d %d", a, b);
   */
    unsigned int arg;
    scanf("%u", &arg);
    printf("result summ = %u", digit_summary(arg));
    /*
    unsigned int digit = 0;
    digit = get_uint();
    //делаем ретерн в функции, помечаем тип возвращаемого значение
    // и присваиваем функцию переменной, без использования адреса
    //digit = increment(digit);
    //переменная вернула значение из функции 
    printf("digit is : %u\n", digit);

    printf("get_max_digit result %u\n", get_max_digit(digit));
    printf("my_pow result %u\n", my_pow_u32(digit, 2));
    printf("is_pow_of_3 %s\n", is_pow_of_3(digit) ? "YES" : "NO");
    */
    printf("\n");
    return 0;
}

unsigned int get_uint(void)
{
    char string;
    unsigned int number = 0;
    while ((string = getchar()) != '\n') {
        if (string >= '0' && string <= '9') {
        //if (string == ('+' || '-' || '/' || '*'))
        number *= 10;
        number += string - '0';
        }
    }
    printf("get_uint is : %u\n", number);
    return number;
}

void remove_spaces(void)
{
    char c;

    while ((c = getchar()) != '.')
    {
        if (c != ' ')
        {
            putchar(c);
        }
    }
}

float sum_of_dig(float sum)
{
    char dig;
    if ((dig >= '0' && dig <= '9')) {
        sum += dig - '0';
        }
    
    printf("Sum of digits %f\n", sum);
    return sum;
}

float str_as_expr(float string)
{
    int num = 0;
    if (string >= '0' && string <= '9') {
        if (string == ('+' || '-' || '/' || '*'))
        num *= 10;
        num += string - '0';
        }
    printf("Result %d\n", num);
    return num;
}


bool is_prime(int arg)
{
    unsigned int i, j;
    bool is_prime;
    for (i = 2; i < arg; i++)
    {
        is_prime = 1;
        for (j = 2; j * j <= i; j++) //j <= sqrt(j)
            if (i % j == 0)
            {
                is_prime = 0;
                break; //exit
            }
        if (is_prime)
            printf("%u is prime\n", i);
    }
}

void print_natur_dividers(int arg)
{
    int counter = 0;
    int current = 1;

    while (current <= arg)
    {
        if ((arg % current) == 0)
        {
            counter++;
            printf("dividers - %d\n", current);
        }
        current++;
    }
    printf("\nNum of dividers %d\n", counter);
}

void print_digits_summ(int arg)
{
    int counter = 0;

    while (arg != 0) {
        counter += arg % 10;
        arg /= 10;    
    }
    printf("Digits summ %d\n", counter);
}

void print_digits_num(int arg)
{
    int counter = 0;

    while (arg != 0)
    {
        arg /= 10;
        counter++;
    }

    printf("Digits num %d\n", counter);
}

void menu_switch(int arg)
{
    switch (arg) {
    case 1: {
        printf("ONE\n");
        break;
    }
    case 2: {
        printf("TWO\n");
        break;
    }
    case 3: {
        printf("THREE\n");
        break;
    }
    default:
        printf("UNKNOWN!\n");
        break;
    }
}

void menu_ifelse(int arg)
{
    if (arg == 1) {
        printf("ONE\n");
    }
    else if (arg == 2) {
        printf("TWO\n");
    }
    else if (arg == 3) {
        printf("THREE\n");
    }
    else {
    printf("UNKNOWN!\n");
    }
}



/* 
void print_n_squares(int N)
{
    float s;
    for (int i = 1; i <= N; i++) {
       s = pow(N,i);
    }
    printf("i^2 = %f", s);
    printf("\n");
}
*/

/*
char out_array(char string[], int range)
{
    for(int sign = 0; sign < range; sign++) {
        printf("ptr %p string[%d] = %d\n", &string[sign], sign, string[sign]);
    }
}

char enter_array(char string[], int range)
{
    char sign;
    printf("enter math expression to calculate it : ");
    while ((sign = getchar()) != '\n')
        for (int sign = 0; sign < range; sign++)
        {

        }
    return string[range];
}
*/

    /*
char get_input(char string[], int range)
{
    printf("enter math expression to calculate it : ");
    while ((*string = getchar()) != '\n')
        putchar(*string);
        range++;
        //printf("\n");
        //printf(" = ptr %p array[%d] = %d\n", &string[range], range, string[range]);
    return *string;
}
*/

    /*
// Массив со строкой для поиска
char string[60] = "test1/test2+test3-test4*test5-test6 test8";
// Набор символов, которые должны входить в искомый сегмент
char separate[10] = {'/', '+', '-', '*', ' '};
// Переменная, в которую будут заноситься начальные адреса частей
// строки str
char *string_index;

printf("Исходная строка: %s\n", string);
printf("Результат разбиения: \n");
// Выделение первой части строки
string_index = strtok(string, separate);

// Выделение последующих частей
while (string_index != NULL)
{
    // Вывод очередной выделенной части
    printf("%s \n", string_index);
    // Выделение очередной части строки
    string_index = strtok(NULL, separate);
*/

    /*
int main(void)
{
    int i;
    char str[80], str2[80];

    scanf("%d%[abcdefg]%s", &i, str, str2);
    printf("%d %s %s", i, str, str2);

    return 0;
}
*/

    /*
    int range;
    char string[range];
    get_input(string, range);
*/

    /*
    int range ;
    char string[range];
    enter_array(string, range);
    out_array(string, range);
*/
