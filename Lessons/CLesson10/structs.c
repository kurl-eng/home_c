#include "structs.h"

#include <stdio.h>

// void print_user(user_t u) (1) ; (2)
void print_user(struct user u)
{
    printf("%s age %d\n", u.name, u.age);
}