#include "../../include/utils/bubblesort.h"

static int ct, st;

void bubbleSort(int *a, int n)
{
    int temp = 0;
    ct = 0, st = 0;
    for (int i = 0; i < n - 1; i++) //次数为n-1次，每次将最小的数排到左边
    {
        for (int j = n - 1; j > i; j--) //前n - i - 1个数比较
        {
            ct++;
            if (*(a + j - 1) > *(a + j))
            {
                temp = *(a + j);
                *(a + j) = *(a + j - 1);
                *(a + j - 1) = temp;
                st++;
            }
        }
    }

    printf("compare %d times, switch %d times.\n", ct, st);
}
