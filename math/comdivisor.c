#include "../include/math/comdivisor.h"

void comDivisorMain()
{
    int d;
    int m;
    int a[NUM];

    printf("Please input %d numbers.\n", NUM);
    inputArr(a, NUM);
    outputArr(a, NUM);

    d = divisor(*a, *(a + 1));
    m = multiple(*a, *(a + 1), d);
    for (int i = 2; i < NUM; i++)
    {
        d = divisor(d, *(a + i));
        m = multiple(m, *(a + i), d);
    }

    printf("Greatest common divisor:%d\n", d);
    printf("Least common multiple:%d\n", m);
}

int divisor(int a1, int a2)
{
    int min = a1 < a2 ? a1 : a2;
    for (int i = min; i > 0; i--)
    {
        if (a1 % i == 0 && a2 % i == 0)
        {
            return i;
        }
    }

    return 1;
}

int multiple(int a1, int a2, int d)
{
    int max = a1 > a2 ? a1 : a2;
    int min = a1 < a2 ? a1 : a2;
    if (max % min == 0)
    {
        return max;
    }

    int m = (max / d) * (min / d) * d;
    if (m > pow(2, sizeof(int) * 8 - 1))
    {
        printf("Over limit!\n");
        exit(0);
    }

    return m;
}
