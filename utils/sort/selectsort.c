#include "../../include/utils/selectsort.h"

static int ct, st;

void selectSort(int *a, int n)
{
    int *max = a; //标记最大数字的指针
    int temp = 0;
    ct = 0, st = 0;

    for (int i = 0; i < n; i++)
    {
        max = a;
        for (int j = 0; j < n - i; j++)
        {
            ct++;
            if (*max < *(a + j))
            {
                max = a + j;
            }
        }

        if (*(a + n - i - 1) != *max)
        {
            temp = *max; //将最大数交换到右边
            *max = *(a + n - i - 1);
            *(a + n - i - 1) = temp;
            st++;
        }
    }

    printf("compare %d times, switch %d times.\n", ct, st);
}
