#include "../include/math/psctriangle.h"

void psctriangle(int n)
{
    SeqList list;
    initSeqList(&list, sizeof(int));
    int *arr = list.node; //保存上一行的数（第一个和最后一个都为1，不用保存）

    int *a;
    int *b;
    int sum;

    for (int i = 0; i < 3; i++) //前3层直接打印
    {
        // print_T(n - 1 - i);
        for (int j = 0; j != i + 1; j++)
        {
            sum = (i == 2 && j == 1) ? 2 : 1;
            printf("%d\t\t", sum);
        }
        printf("\n");
    }

    sum = 2;
    insertSeqNode(&list, 0, &sum);
    for (int i = 3; i < n; i++) //第4层开始
    {
        // print_T(n - 1 - i);

        sum = 1;
        insertSeqNode(&list, 0, &sum); //首先添加一个1
        printf("%d\t\t", sum);

        for (int j = 0; j < i - 1; j++)
        {
            a = searchSeqNode(&list, j);
            if (j == i - 2) //最后一个数
            {
                sum = *a + 1;
                modifySeqNode(&list, j, &sum);
            }
            else
            {
                b = searchSeqNode(&list, j + 1);
                sum = *a + *b; //本行第j个数为上一行第j个和第j+1个数的和
                modifySeqNode(&list, j, &sum);
            }
            printf("%d\t\t", sum);
        }

        printf("%d\n", 1);
    }
}

void print_T(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t");
    }
}