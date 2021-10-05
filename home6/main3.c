#include <stdio.h>

void print_title(void);

int get_string(void);

void print_out(void);

int main(void)
{
    print_title();
    char string = get_string();
    print_out();

    return 0;
}

void print_out(void)
{
    printf("Summary %d symbols.", &get_string);
}

int get_string(void)
{
    char sign;
    int  summary = 0;
    while ((sign = getchar()) != '\n'){
        if (sign >= '0' && sign <= 'z'){
            summary += sign - 'a';
        }
    }
    printf("Summary %d symbols\n", summary);

    //return summary;
}

void print_title(void)
{
    printf("Enter text with digits to count symbols of it: \n");
}
