#include "../include/math/duequation.h"

void dUEquationMain()
{
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;
L1:
    printf("Please input a,b,c:");
    scanf("%d,%d,%d", &a, &b, &c);

    if (a == 0)
    {
        printf("It's not LE2U,Please input again.\n");
        goto L1;
    }

    float n = pow(b, 2) - 4 * a * c;
    float s1, s2;

    if (n < 0)
    {
        printf("Unsolvable!\n");
    }
    else
    {
        s1 = ((-b) + sqrt(n)) / 2;
        s2 = ((-b) - sqrt(n)) / 2;
        printf("s1 = %0.2f,s2 = %0.2f\n", s1, s2);
    }
}