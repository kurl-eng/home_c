//объявление библиотек прототипов функций
#include <stdio.h>
#include <stdbool.h>

//вынос функции оператора ввода для удобства
int get_user_input(void);

//вынос функции условий вывода переменной ввода
bool is_prime(int arg);

//вынос функции вывода значения основной функции
//int user_output(is_prime);

//объявление главной функции тела программы
int main(void)
{
    //локальная переменная оператора ввода главной функции
    //присваивает значение функции переменной
    int user_input = get_user_input();
    //int user_output = is_prime(int arg);

    //функция вывода услвоий переменной is_prime
    printf("Number %d is prime %s\n", user_input, is_prime(user_input) ? "TRUE" : "FALSE");
    
}

//функция логического оператора вычисляет значение arg 
bool is_prime(int arg){
    bool prime = true;
    //условие переменной prime при значении true
    if (arg <= 2) {
        return true;
    }
    //условие переменной prime при значении false
    //где введенное значение arg сравнивается со счетчиком
    for (int i = 2; i < arg; i++) {
        //условие деления на счетчик для определения остатка от деления
        if ((arg % i) == 0) {
        return false;
        }
    }
    //возврат переменной prime функции со значением arg
    return prime;
}

/*int user_output(is_prime)
{
    printf("Number %d is prime %s\n", get_user_input, is_prime(get_user_input) ? "TRUE" : "FALSE");
}*/

//функция оператора ввода получает данные от пользователя
int get_user_input(void)
{
    //переменная целочисленного значения
    int input; 
    //вывод иструкции программы
    printf("Please enter integer number and press Enter : \n");
    //функция обработки потока ввода данных завершается через ввод Enter
    scanf("%d", &input);
    //возврат данных функции ввода
    return input;
}
