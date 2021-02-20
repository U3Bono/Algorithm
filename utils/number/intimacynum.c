#include "../../include/utils/intimacynum.h"

int isIntimacyNum(int n)
{
    int sum1, sum2;
    printf("Please input limit:");

    sum1 = sum2 = 0;
    for (int j = 1; j < n; j++)
    {
        if (n % j == 0)
        {
            sum1 += j;
        }
    }
    for (int j = 1; j < sum1; j++)
    {
        if (sum1 % j == 0)
        {
            sum2 += j;
        }
    }
    if (sum2 == n && n < sum1)
    {
        return 1;
    }

    return 0;
}
