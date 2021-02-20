#include "../../include/utils/mergesort.h"

void mergeSort(int *a, int n)
{
    int *temp = malloc(sizeof(int) * n);
    mSort(a, 0, n - 1, temp);
    free(temp);
}

void mSort(int *a, int low, int high, int *temp)
{
    if (low == high) //数组还剩一个元素时返回
    {
        return;
    }

    int mid = low + (high - low) / 2;

    mSort(a, low, mid, temp);      //排好前半段
    mSort(a, mid + 1, high, temp); //排好后半段

    /*  此时表示前半段是有序的，后半段是有序的 */

    int i = low;     //前半段指针
    int j = mid + 1; //后半段指针
    int k = 0;       //临时数组指针
    while (j <= high && i <= mid)
    {
        *(temp + (k++)) = *(a + i) < *(a + j) ? *(a + (i++)) : *(a + (j++)); //前半段和后半段比较，放入临时数组
    }
    while (i < mid + 1) //前半段剩余的数放入临时数组
    {
        *(temp + (k++)) = *(a + (i++));
    }
    while (j < high + 1) //后半段剩余的数放入临时数组
    {
        *(temp + (k++)) = *(a + (j++));
    }

    for (k = 0; low < high + 1; k++) //将临时数组排好的数放回原数组
    {
        *(a + low++) = *(temp + k);
    }
}