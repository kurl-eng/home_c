#ifndef STRUCTS_H
#define STRUCTS_H

struct user {
    char name[30];
    int age;
}; //user_t; (2)

// typedef struct user user_t; (1)
// void print_user(user_t u); (1)

//typedef struct user user_t; (2)

void print_user(struct user u);

#endif