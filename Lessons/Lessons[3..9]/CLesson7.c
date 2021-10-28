#include <stdio.h>
#include <stdbool.h>

//функция отмеченая модификатором static локализуется в данном файле
void test(void); //static test(void); instead of void test(void);

//при использовании указателя переменной мы копируем только переменную,
//а не всю функцию из памяти, тем ссамым ускоряем доступ к памяти и вычисления.
void swap(int *a, int *b);

bool get_user_input(int *a, int *b);

void recursion_test(void);

unsigned int my_factorial(unsigned int n);

unsigned int my_factorial_for(unsigned int n);

//fact(3) = 3 * 2 * 1
//fact(5) = 5 * 4 * 3 * 2 * 1

void recursion_for(int i, int n);

void print_rev(void);

void to_bin(unsigned int n); //10 => 1010

unsigned int float_as_int(float arg);

unsigned int digit_summary(unsigned int n);

void print_digit_reverse(unsigned int n);

void print_digit_straight(unsigned int n);

unsigned int get_max(void);

int main(void)
{
        
    /*test();
    test();
    test();*/
   
    //после обозначения переменной, 
    //к ним можно ссылаться по адресу через *(link to), &(link from)
    /*int a = 5, b = 10;
    int *p_a = &a;
    int *p_b = &b;
    */

    /*float f_val = 123.456f;
    //int f_as_int = f_val;
    int f_as_int = *(int *)&f_val;
    printf("%d\n", f_as_int);
    */

    //scanf("%d%d", p_a, p_b); use next
    //scanf modify to validate of param's
    /*bool ret = get_user_input(&a, &b);
    if (ret == false) {
        printf("Error!\n");
        return -1;
    }
    */

    //sizeof
    //printf("sizeof int %lu sizeof int * %lu\n", sizeof(a), sizeof(p_a));
    
    //printf("%d %d\n", a, b);
   
    //для получения адреса памяти переменной используют &a
    
    /*swap(p_a, p_b);
    printf("%d %d\n", a, b);
    */
    
    //recursive_test();

    /*factorial examples with recursion and cycle for
    unsigned int arg;
    //you can send result exactly in printf with function
    //unsigned int result;
    
    scanf("%u", &arg);

    
    //result = my_factorial(arg);
    printf("recursion factorial result: %u\n", my_factorial(arg));

    
    //result = my_factorial_for(arg);
    printf("for cycle factorial result: %u\n", my_factorial_for(arg));
    */  

    //recursion output printf with args
    //recursion_for(1, 10);

    //print_rev();

    //to_bin(254);

    //printf("float_as_int: %u\n", float_as_int(123.45));
    //add minus to check seniour sign of binary
    //to_bin(float_as_int(-1.5)); //IEEE754 table of signs

    //digit_summary
    /*unsigned int arg;
    scanf("%u", &arg);
    printf("result of %u\n", digit_summary(arg));
    */

    //print_digit_reverse
    /*unsigned int arg;
    scanf("%u", &arg);
    print_digit_reverse(arg);
    */

    //print_digit_straight
    /*unsigned int arg;
    scanf("%u", &arg);
    print_digit_straight(arg);
    */

    unsigned int max = get_max();
    printf("max %u", max);

    printf("\n");
    return 0;
}

unsigned int get_max(void)
{
    unsigned int number, max;
    scanf("%u", &number);

    if (number == 0) {
        return 0;
    }

    max = get_max();

    if (max < number)
        max = number;
        return max;
}

void print_digit_straight(unsigned int n)
{
    if (n <= 9)
    {
        printf("%d ", n);
        return;
    }
    print_digit_straight(n / 10);
    printf("%d ", n % 10);
    
}

void print_digit_reverse(unsigned int n)
{
    if (n <= 9) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n % 10);
    print_digit_reverse(n /10);
}   

unsigned int digit_summary(unsigned int n)
{
    if (n <= 9){
        return n;
    }

    return (n % 10) + digit_summary(n / 10);
}

unsigned int float_as_int(float arg)
{
    return *(unsigned int*)&arg;
}

void to_bin(unsigned int n)
{
    if (n <= 1) {
        putchar('0' + n);
        return;
    }
    //changing place of function with recursion
    //for reverse symbols sequence in stack
    to_bin(n >> 1);
    putchar('0' + (0x1 & n));
    
}

void print_rev(void)
{
    char ch;

    scanf("%c", &ch);

    if (ch != '\n') {
        print_rev(); //straight in stack (reverse output)
        printf("%c", ch);
        print_rev(); //reverse in stack (straight output)
    }
}

void recursion_for(int i, int n)
{
    if (i == n + 1) {
        return;
    }
    printf("%d ", i);
    recursion_for(i + 1, n);
}

unsigned int my_factorial_for(unsigned int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

//tail recursion call
unsigned int my_factorial(unsigned int n)
{
    //условие останова
    if (n <= 1){
        return 1;
    }
    //шаг рекурсии
    return n * my_factorial(n - 1);
}

//для обозначения условий выхода из рекурсии
void recursion_test(void)
{   
    static int count = 5;
    count--;
    if(count == 0){
        return;
    }
    printf("У попа была собака, он её любил, а потом что-то пошло не так\n");
    recursion_test();
}

bool get_user_input(int *a, int *b)
{
    int retcode;

    retcode = scanf("%d%d", a, b);
    if (retcode == 2){
        return true;
    } return false;
}

//для передачи адреса памяти переменной используют int *a
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    //пример рекурсии
    //swap(int *a, int *b);
}

void test(void)
{
    //модификатор static сохраняет результаты переменной при выходе из функции
    static int a = 5;
    a++;
    printf("%d\n", a);
}
