#include <stdio.h>
#include <string.h>

void print_operands(int *op, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", op[i]);
    }
    printf("\n");
}

void print_operations(char *op, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%c ", op[i]);
    }
    printf("\n");
}

int main()
{
    // строка для примера
    const char *string = "(100+200+300)/5";

    // массив и счетчик операндов. Для примера, пусть будет максимум 100
    int n_operands = 0;
    int operands[100] = {0};

    // массив и счетчик операций. Для примера, пусть будет максимум 100
    int n_operations = 0;
    char operations[100] = {0};

    for (int i = 0; i <= strlen(string); i++) {
        char ch = string[i];
        // формируем операнды
        if (ch >= '0' && ch <= '9') {
            operands[n_operands] *= 10;
            operands[n_operands] += ch - '0';
        }

        // формируем операции
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            n_operands++;
            operations[n_operations] = ch;
            n_operations++;
        }
    }

    // число операндов всегда должно быть на 1 больше чем операций
    if (n_operations == n_operands) {
        n_operands++;
    }

    // выводим массивы из того, что получилось
    print_operands(operands, n_operands);
    print_operations(operations, n_operations);

    //первый операнд участвует в операции в любом случае
    int result = operands[0];

    for (int i = 0; i < n_operations; i++) {
        switch (operations[i]) {
            case '+': {
                result += operands[i + 1];
            break;
            }   
            case '-': {
            result -= operands[i + 1];
            break;
            }
            case '*': {
            result *= operands[i + 1];
            break;
            }
            case '/': {
            result /= operands[i + 1];
            break;
            }
        }
    }

    printf("n_operations %d n_operands %d\n", n_operations, n_operands);

    printf("result %d\n", result);

    return 0;
}
