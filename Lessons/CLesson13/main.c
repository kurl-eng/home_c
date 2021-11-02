#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//for cpu time test, use man!
#include <time.h>
#include "stack.h"
#include "list.h"

//valgrind ./main for memory
//time ./main for cpu speed
int main (int argc, char **argv)
{
    clock_t c_start, c_end;
    //c_start = clock();

//LISTS:
    struct list *l = list_new(0);
    //printf("sizeof struct %lu\n", sizeof(struct list));

    for (int i = 1; i <= 10; i++) {
        list_add(l, i);
    }

    list_print(l);

    struct list *l_find = list_find(l, 5);
    if (l_find) {
        printf("l == 5 found %p\n", l_find);
    }
    
    l_find = list_get_i(l, 5);
    if (l_find) {
        printf("l[5] found %p %d\n", l_find, l_find -> data);
    }
    
    printf("List length %d\n", list_length(l));
    c_start = clock();
    for (int i = 0; i < 10000; i++) {
        list_add(l, i);
    }
    c_end = clock();
    printf("App time: %lu mkrSec\n", c_end - c_start);
    printf("List length %d\n", list_length(l));
    
    list_free(&l);
//ENDLIST:

/*
    if (5 < 10) {
        goto ENDSTACK;
    } else {
        printf("no\n");
    }
STACK:
    struct stack *st = stack_new();
    //printf("ptr %p\n", st);

    for (int i = 0; i < 10; i++) {
        printf(" %d", i);
        stack_push(st, i);
    }
    printf("\n");

    for (int i = 0; i < 20; i++) {
        int tmp;
       if  (stack_pop(st, &tmp)) {
        printf(" %d", tmp);
       }
    }
    stack_free(&st);
    //printf("ptr %p\n", st);
ENDSTACK:
goto STACK;
    //c_end = clock();
    //printf("App time: %lu mkrSec\n", c_end - c_start);
*/
    printf("\n");
    return 0;
}

/*  //при подключенной библиотеке time.h моэно использовать
    //clock_t c_start, c_end;
    int *array = (int *)malloc(sizeof(int) * 10);

    array = (int *)realloc(array, sizeof(int) * 100000000);

    //c_start = clock();
    for (int i = 0; i < 100000000; i++) {
        array[i] = rand() % 100;
    }
    //c_end = clock();
    //printf("Clocks %lu\n", c_end - c_start);

    free(array);
 */