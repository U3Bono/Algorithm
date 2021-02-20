#include "../include/math/fibonacci.h"

int fibonacciMain()
{
    TYPE a[] = {1, 1, 0};
    TYPE t; //最大数
    printf("Please input times:");
    scanf("%d", &t);

    int n; //下标
    for (int i = 0; i < t; i++)
    {
        n = i % 3;

        a[n] = 0;
        a[n] += a[0] + a[1] + a[2];

        printf("%d\t", a[n]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }

        if (a[n] > pow(2, sizeof(TYPE) * 8 - 2))
        {
            printf("Over limit!\n");
            break;
        }
    }

    printf("\n");
    return 0;
}
