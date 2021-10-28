//объявление библиотек прототипов функций
#include <stdio.h>
#include <stdbool.h>

//вынос функции оператора ввода для удобства
int get_user_input(void);

//вынос функции условий вывода переменной ввода
bool is_prime(int arg);

//объявление главной функции тела программы
int main(void)
{
    //локальная переменная оператора ввода главной функции
    //присваивает значение функции переменной
    int user_input = get_user_input();

    //функция вывода услвоий переменной is_prime
    printf("Number %d is prime %s\n", user_input, is_prime(user_input) ? "TRUE" : "FALSE");

    int counter = 2;
    while(user_input){
        if (is_prime(counter)){
            (user_input % counter) == 0;
            user_input --;
            printf("%d ", counter);
        }
        counter ++;
    }

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
