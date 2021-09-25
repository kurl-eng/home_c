#include <stdio.h>

main()
{
    int r, lc, sc, vc;
    int pi = 3.1415;
    printf("Enter radius of cirlce and press Enter\n");
        scanf(r);

    lc = 2 * pi * r;
    sc = pi * r * r;
    vc = 4/3 * pi * r * r * r;
    
    printf("Within radius = \n", r ,"\n");
    printf("\n""long of circle is ", lc,"\n");
    printf("\n""square of cirlce is ", sc,"\n");
    printf("\n""volume of circle is ", vc,"\n");
    printf("\n");
    return 0;
}