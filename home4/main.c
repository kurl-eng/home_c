#include <stdio.h>
#include <stdint.h>

int main()
{
    unsigned char num = 0, val = 0;
    int shift = 0;

    printf("Enter number and shift value\n");

    scanf("%x%d", &num, &shift);

    if (shift > 0) {
        val = num << shift;
        printf("Input: %x shift right: %d\n Result: %x\n", num, shift, val);
    } else if (shift < 0) { 
        val = num >> (~shift + 1);
        printf("Input: %x shift left: %d\n Result: %x\n", num, shift, val);
    } else {
        printf("Input: %x shift: %d\n", num, shift);
        printf("Zero shift is not defined");
    }

    return 0;
}