#include "../../include/utils/shellsort.h"

static int ct, st;

void shellSort(int *a, int n)
{
    int gap = n;
    int i, j, temp;
    ct = 0, st = 0;

    do
    {
        gap /= 3; //影响性能
        for (i = gap; i < n; i++)
        {
            ct++;
            for (j = i; *(a + j - gap) > *(a + j) && j > (gap - 1); j -= gap)
            {
                temp = *(a + j);
                *(a + j) = *(a + j - gap);
                *(a + j - gap) = temp;
                st++;
            }
        }
    } while (gap > 0);
    printf("compare %d times, switch %d times.\n", ct, st);
}