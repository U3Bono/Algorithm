#include "../../include/utils/heapsort.h"

static int ct, st;

void heapSort(int *a, int n)
{
    int temp;
    ct = 0, st = 0;

    for (int i = 0; i < n - 1; i++)
    {
        heapAdjust(a, n - i);
        temp = *a;
        *a = *(a + n - i - 1);
        *(a + n - i - 1) = temp;

        st++;
    }

    printf("compare %d times, switch %d times.\n", ct, st);
}

void heapAdjust(int *a, int n)
{
    int l, r, max, temp;
    int i, j;

    for (i = n / 2 - 1; i > -1; i--) //从最后一个父节点开始
    {
        j = i;
        while (j < n / 2) //调整当前父节点及之前父节点
        {

            l = 2 * j + 1; //左孩子
            r = 2 * j + 2; //右孩子

            max = l; //左右孩子中最大值
            if (r < n)
            {
                max = *(a + l) > *(a + r) ? l : r;
            }

            ct++;
            if (*(a + max) > *(a + j)) //父节点小于左右堆交换
            {
                temp = *(a + max);
                *(a + max) = *(a + j);
                *(a + j) = temp;
                j = max; //下一个父节点只会为交换后的子节点
                st++;
            }
            else //节点大于左右子树，符合堆
            {
                break;
            }
        }
    }
}