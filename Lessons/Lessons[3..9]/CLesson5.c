#include <stdio.h>
#include <inttypes.h>
#include <math.h> // for pow func
#include <stdbool.h>

//void printsmth(void)
//int printsmth(void)
//int get_user_input(void)

//но можно нажать стрелку чтобы свернуть
int get_user_input(void); //int arg .. без void тоже работает
void menu_ifelse(int arg);
void menu_switch(int arg);
void print_digits_num(int arg);
void print_digits_summ(int arg);
void print_digits_mult(int arg);
void print_natur_dividers(int arg);
void print_n_squares(int N);
void print_n_2k_for(int N);
void print_n_2k_while(int N);
void print_natur_polindrom(int arg);
void print_n_fibonaci(int arg);
bool is_prime(int arg);

/* goto skip; //better not used it
printf("What you skipping");
skip;
*/

//определение перечислимого типа, 
//содержащего единственнуюконстанту N, имеющую значение 100
enum { N = 100 }

/* Переменные и идентификаторы пишутся в camelCase.
   Константы пишутся в SCREAMING_CASE */

//int delim = 20;
//глбальная переменная лучше писать так g_delim или global_delim
// const int CONST_VAL = 10;

/* int main (void)
{
    int smth;
    //const int delim = 20;

    smth = get_user_input(); //delim
    printf("1 You've enterd %d\n", smth);
    
    //smth = get_user_input(20);
    //printf("2 You've enterd %d\n", smth);

    return 0;
}
*/

main(void) //int
{
    int from_user = get_user_input();
    

    /*printf("number %d is prime %s\n", from_user,
     is_prime(from_user) ? "TRUE" : "FALSE");
    */

    /*  print_n_fibonaci(from_user);
    print_natur_polindrom(from_user); 
    print_n_2k_for(from_user);
    print_n_2k_while(from_user);
    print_n_squares(from_user);
    print_digits_summ(from_user);
    print_digits_num(from_user);
    print_digits_mult(from_user);
    print_natur_dividers(from_user);
        */
    menu_ifelse(from_user);
    menu_switch(from_user);


    /*  int n, count;
    printf("Input number:\n");
    scanf("%d\n", &n);
    count = 0;
    while (n != 0)
    {
        count ++;
        n = n / 10; //Changing value of int
    }
    
    printf("In %d found %d digits\n", n, count);
*/

    /*  int delim = 5;
    //while (delim != 0) // 5 times
    do {                // 
        printf("Hi\n");
        delim --;
    } while (delim != 0); // 5 time without do 1 time

    //printf("Hi\n");
    //printf("Hi\n");
    //printf("Hi\n");
    //printf("Hi\n");
    //printf("Hi\n");
    */

    /*  uint32_t n, i = 2;
    scanf("%" PRIu32, n);
    while (i <= n) {
        if (n % i == 0){
            printf("%" PRIu32 " ", i);
            n /= i;
        } else {
            i++;
        }
    }
    printf("Kek\n", n);
    */

    /*  for (int i = 1; i <= from_user; i++) {
        printf("iteration %d of %d\n", i, from_user);
        if (i == (from_user + 1)) {
            i ++;
            printf("iteration %d of %d\n", i, from_user);
        }
    }
*/
    /*//while analog
    int i = 1;
    while (i <= from_user) {
        printf("iteration %d of %d\n", i, from_user);
        i++;
    }
    */

    return 0;
}

bool is_prime(int arg)
{    

    unsigned int i, j;
    bool is_prime;
    for (i = 2; i < arg; i++) {
        is_prime = 1;
        for (j = 2; j * j <= i; j++) //j <= sqrt(j)
        if (i % j == 0) {
            is_prime = 0;
            break; //exit
        }
        if (is_prime)
        printf("%u is prime\n", i);
    }

    /*
    bool prime = true;

    if (arg <= 2) {
        return true;
    }

    for (int i = 2; i < arg; i++) {
        if ((arg % i) == 0) {
            return false;
        }
    }

    return prime;
    */
}

void print_n_fibonaci(int arg)
{
    int f1, f2 = 1, lf, i;

    if (arg == 1) {
        printf("0 1\n");
    }   else if (arg !=0 ) {
        printf("0 1 1 ");
        for (i = 1; i < arg; i++) {
            lf = f1 + f2;
            f1 = f2;
            f2 = lf;
            printf("%d ", f2);
        }
    }
}

void print_natur_polindrom(int arg)
{
    uint32_t count = 0;
    for (uint32_t i = 11; i <= 999; i++) {
        if (i < 100 && i % 10 == i / 10) {
            count ++;
            printf("%" PRIu32 " ", i);
        } else if (i >= 100 && i & 10 == i / 100) {
            count ++;
            printf("%" PRIu32 " ", i);
        }
    }
    printf("Total polindroms %" PRIu32 "\n", count);
    //return 0; if into main
}

void print_n_2k_while(int N)
{
    int counter = 1;
    while (counter <= N) {
        counter <<= 1;
    }
    printf("%d\n", counter);
}

void print_n_2k_for(int N)
{
    /*
    int counter, pow2 = 1;
    for (counter = 1; pow2 < N; counter ++)
        pow2 <<= 1; //pow2 = pow2 * 2
        printf("%d\n", pow2);
    */
    
    
    int counter;
    for (counter = 1; counter <= N; counter <<= 1) //counter *= 2
    printf("%d\n", counter);
    
}

/*
void print_n_squares(int N) 
{
    for (int i = 1; i <= N; i++) {
        
        int s = pow(i, 2);
        printf("%d ", s);*/
        //printf("%d ", i*i);
        
        /*int s = pow(N, i);
        printf("%d ", s);*/
/*    }
    printf("\n");
}
*/

void print_natur_dividers(int arg)
{
    int counter = 0;
    int current = 1;

    while (current != (arg + 1)) {
        if ((arg % current) == 0) {
            counter ++;
            printf("%d ", current);
        }
        current ++;
    }

    printf("\nNum of dividers %d\n", counter);
}

void print_digits_mult(int arg) {
    
    int counter = 1;

    while (arg != 0)
    {
       
        counter *= arg % 10;
        arg /= 10;
    }

    printf("Digits multi %d\n", counter);
}

void print_digits_summ(int arg) {
    
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

    while (arg != 0) {
        arg /= 10;
        counter ++;
    }

    printf("Digits num %d\n", counter);
}

void menu_ifelse(int arg)
{
    //return;  quit func
    if (arg == 1)
    {
        printf("ONE\n");
        
    }
    else if (arg == 2)
    {
        printf("TWO\n");
    }
    else if (arg == 3)
    {
        printf("THREE\n");
    }
    else
    {
        printf("MORE THAN THREE\n");
    }
}

void menu_switch(int arg) 
{
    switch (arg)
    {
    case 1:
    {   // можно юзать кейс без скобок как в дефолт
        // скобки сворачивают код
        printf("ONE\n");
        break;
    }
    case 2:
    {
        printf("TWO\n");
        break;
    }
    case 3:
    {
        printf("THREE\n");
        break;
    }
    default:
        printf("MORE THAN THREE\n");
        break;
    }
    return;
}

int get_user_input(void) //int arg
{
    int input;
    int rc;

    printf("Please enter integer number : \n");
    rc = scanf("%d", &input);
    if (rc != 1) {
        printf("Error!\n");
    }

    /* if (input > arg)
    {
        printf("Error! you've entered > %d\n", arg);
    } */
    //printf("Hi\n");

    return input;
}