#include "../../include/utils/perfectnum.h"

int isPerfectNum(int n)
{
    int sum;
    sum = 0;
    for (int j = 1; j < n; j++)
    {
        if (n % j == 0)
        {
            sum += j;
        }
    }
    if (sum == n)
    {
        return 1;
    }

    return 0;
}
