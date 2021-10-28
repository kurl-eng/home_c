#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool print_circs(float *x, float *y, float *r);
bool is_target_hit(float *x, float *y, float *r);
int main()
{
    float x, y, r;
    print_circs(&x, &y, &r);
    is_target_hit(&x, &y, &r);
    printf("\n");
    return 0;
}
bool is_target_hit(float *x, float *y, float *r)
{
    float hit = (*x * *x + *y * *y);
    float target = (*r * *r);
    if (hit <= target) {printf("Вы попали в мишень x/y : %.2f в радиусе : %.2f\n", hit, target);}
    else if (hit > target) {printf("Значение x/y : %.2f  вне радиуса : %.2f\n", hit, target);}
}
bool print_circs(float *x, float *y, float *r)
{
    printf("Введите значение x, y - точки и r - радиуса :\n");
    int retry = scanf("%f %f %f\n", x, y, r);
    if (r <= 0) {
        is_target_hit(x, y, r);
        printf("Введите не отрицательный и не нулевой радиус\n");
    } else if (r > 0) {is_target_hit(x, y, r);}
    else if ((x && y) == 0, r > 0) {
        printf("x : %.2f, y : %.2f, r : %.2f.\n", *x, *y, *r);
        printf("Вы попали в центр круга. retry = %d \n", retry);
    }
}