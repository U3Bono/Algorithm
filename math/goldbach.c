#include "../include/math/goldbach.h"

void goldbachMain()
{
    int n;
    printf("Please input the limit(< %0.0lf):", pow(2, (sizeof(int) - 1) * 8));
    scanf("%d", &n);

    for (int i = 3; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j < i / 2 + 1; j++)
            {
                if (isPrime(j) && isPrime(i - j))
                {
                    printf("%d = %d + %d\n", i, j, i - j);
                }
            }
        }
    }
}
