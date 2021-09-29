#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t num, val;
    int shift;

    printf("Enter number and shift value\n");

    scanf("%x%d", &num, &shift);

    if (shift > 0) {
        val = num >> shift;
        printf("Input: %x shift right: %d\n Result: %x\n", num, shift, val);
    } else if (shift < 0) { 
        val = num << shift;
        printf("Input: %x shift left: %d\n Result: %x\n", num, shift, val);
    } else {
        printf("Input: %x shift: %d\n", num, shift);
        printf("Zero shift is not defined");
    }

    return 0;
}