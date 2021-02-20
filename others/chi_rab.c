#include "../include/others/chi_rab.h"

void chi_RabMain()
{
    int h, f;
    int c, r;

L1:
    printf("Please input the number of head:");
    scanf("%d", &h);
    printf("Please input the number of foot:");
    scanf("%d", &f);

    r = (f - 2 * h) / 2;
    c = h - r;

    if (((f - 2 * h) % 2) != 0 || r < 0 || c < 0)
    {
        printf("The number you input is error!\n");
        goto L1;
    }
    else
    {
        printf("The number of chicken is %d.\n", c);
        printf("The number of rabit is %d.\n", r);
    }
}
