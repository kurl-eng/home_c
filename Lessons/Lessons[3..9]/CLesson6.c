#include <stdio.h>

//создаем заголовок файла путем объявления прототипов функций
void str_replace_to_upper(void);
void sum_of_dig (void);
void str_as_num(void);
void remove_spaces(void);
unsigned int get_uint(void);
//для возврата значения void >> insigned int
void increment(unsigned int arg);
int my_abs(int arg);
unsigned int my_pow_u32(unsigned int arg, unsigned int p);
unsigned int is_pow_of_3(unsigned int arg);
unsigned int get_max_dig(unsigned int arg);
unsigned int get_even_num(unsigned int arg);

//посимвольное управление потоком В/В
    //буферизированный и не буферизированный
    //1. Реагировать на вводимый поток данных (не буферизированно)
    //   например игры или контроллеры. сенсоры или датчики (двояко)
    //2. Обработки потока после ввода определенной команды
    //   или выполнения условия (буферизированно)
    //   например для промежуточных вычислений.
    //   Макросы - надстройки над другими функциями,
    //   позволяют работать посимвольно с В/В.
    //   Стандартные таблицы символов - ASCI & UTF-8
    //getchar() and putchar() examples

int main(void)
{
    /*char c;
    //ending cycle on '\n' (Enter)
    while((c = getchar()) != '.'){
        putchar(c);
    }
    */

    /*c = getchar();
    putchar(c);
    c = getchar();
    putchar(c);
    c = getchar();
    */

    //putchar(c);
    // on enter symbol + '\n'
    // continue and break functions examples (Lesson5)
    /* 
    for (int i = 0; i < 10; i++){
        //выполение условия if переменной i == 5 оператором continue
        //переведет цикл на новую итерацию
        if (i == 5) continue;
        //завершение for в условии if i == 7 оператором break
        if (i == 7) break;
        printf("Iteration %d\n", i);
    }
    */
    
    //int input;
    unsigned int test = 0;
    test = get_uint();
    
    //объявление переменных для вызова функций
    str_replace_to_upper(); //call into assembler
    //sum_of_dig();
    //str_as_num();
    //remove_spaces();
    //increment(test); //for return >> test = increment(test);
    //my_abs(test);

    //scanf("%d", &input);

    //printf("even count %d\n", get_even_num(test));
    //printf("get max digit result %u\n", get_max_dig(test));
    //printf("got_inc %u\n", test);
    //printf("is_pow_of_3 %s\n", is_pow_of_3);
    //printf("my_abs = %d\n", my_abs(input));
    //printf("got %u\n", test);
    //printf("my_pow %u\n", my_pow_u32(test, 2));
    //printf("Is pow 3 %s\n", is_pow_of_3(test) ? "YES" : "NO");
    return 0;
}

void str_replace_to_upper(void)
{
    char c;
    //сравним цикл ввода с символом ввода для определения функции
    // 'a' || 'z' > outside range, 'a' && 'z' > inside range
    while ((c = getchar()) != '\n')
    {
        if (c >= 'a' && c <= 'z')
        {
            c = c - 'a' + 'A';
            //putchar(c);
        }           // else {
        putchar(c); //так работает, но можно добавить блок else {}
        //}
    }
}

void sum_of_dig(void)
{
    char c;
    int sum = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
    }
    printf ("Sum of digits %d\n", sum);
}

void str_as_num(void)
{
    char c;
    int num = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            num *= 10;
            num += c - '0';
        }
    }
    printf("Result %d\n", num);
}

void remove_spaces(void)
{
    char c;

    while ((c = getchar()) != '.') //space is \s but need google it
    {
        if (c != ' ')
        {
            putchar(c);
        }
    }
}

unsigned int get_uint(void)
{
    char c;
    unsigned int num = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            num *= 10;
            num += c - '0';
        }
    }
    return num;
}

void increment(unsigned int arg)
{
    //is exactly insigned int arg = main:test; return
    arg = arg + 10;
    printf("result = %u\n", arg);
    // to return arg add
    //return arg;
}

int my_abs(int arg)
{
    //return (arg < 0) ? -arg : arg; \\тринарный оператор условия
    if (arg < 0){
        return -arg;
    } else {
        return arg;
    }
}

unsigned int my_pow_u32(unsigned int arg, unsigned int p)
{
    unsigned int result = 1;
    for (int i = p; i > 0; i--)
        result *= arg;
    return result;
}

unsigned int is_pow_of_3(unsigned int arg)
{
    unsigned int base = 3;
    while (base <= arg)
    {
        if (base == arg)
        {
            return 1;
        }
        base *= 3;
    }
    return 0;
}

unsigned int get_max_dig(unsigned int arg)
{
    unsigned int max = arg % 10;

    while (arg)
    {
        if ((arg % 10) > max)
            max = arg % 10;
        arg /= 10;
    }
    return max;
}

unsigned int get_even_num(unsigned int arg)
{
    unsigned int count = 0;

    while (arg) // or here (arg /= 10)
    {
        if ((arg % 10) & 0x1)
        {
            arg /= 10;
            continue;
        }
        arg /= 10;
        count++;
    }
    return count;
}
