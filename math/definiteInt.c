#include "../include/math/definiteInt.h"

void definiteIntMain()
{
    int a, b;
    double sum = 0;

    printf("Please input a,b:");
    scanf("%d,%d", &a, &b);

    for (double i = 0; i < N; i++)
    {
        sum += func(a + (b - a) * (i / N)) * (b - a) / N; //定积分定义
    }

    printf("The integration is %lf\n", sum);
}