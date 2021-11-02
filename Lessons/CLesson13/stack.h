#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_DEF_SIZE 16

struct stack {
    //массив
    int *data;
    //размер
    int size;
    //stack pointer 
    //(*data++) > sp++; (*data--) > sp-- >= 0
    int sp;
};

struct stack *stack_new(void);
void stack_free(struct stack **st);

//push, pop
void stack_push(struct stack *st, int value);
bool stack_pop(struct stack *st, int *out_value);

#endif // !STACH_H