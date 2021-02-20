#include "../../include/utils/quicksort.h"

void quickSort(int *a, int n)
{
    qSort(a, 0, n - 1);
}

void qSort(int *a, int low, int high)
{

    if (low >= high)
    {
        return;
    }

    int i = low;           //低位指针
    int j = high;          //高位指针
    int base = *(a + low); //基准点

    while (i < j)
    {
        while (*(a + j) >= base && i < j) //高位来到小于基准点的位置
        {
            j--;
        }
        if (i < j) //将小于基准点的数填入左边
        {
            *(a + i++) = *(a + j);
        }
        while (*(a + i) <= base && i < j) //低位来到大于基准点的位置
        {
            i++;
        }
        if (i < j) //将大于基准点的数填入右边
        {
            *(a + j) = *(a + i);
            j = j < high ? j + 1 : j;
        }
    }

    *(a + i) = base; //将基准数填入中位置，此时指针左边的数小于基准点，右边的数大于基准点

    qSort(a, low, i - 1);
    qSort(a, i + 1, high);
}
