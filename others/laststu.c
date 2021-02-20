#include "../include/others/laststu.h"

void lastStuMain()
{
    int stu;
    printf("Please input the number of students:");
    scanf("%d", &stu);

    int *a = malloc(sizeof(int) * stu);

    for (int i = 0; i < stu; i++)
    {
        *(a + i) = i + 1;
    }

    int n = 1; //报号
    int p = 0; //序号
    int m = 0; //人数
    while (1)
    {
        if (*(a + p) != 0) //未淘汰的学生
        {
            m++;            //统计人数
            if (n % 3 == 0) //报号为3淘汰
            {
                *(a + p) = 0;
                m--;
            }
            n++;       //下一个人的报号
            if (n > 3) //大于3从1开始
            {
                n = 1;
            }
        }
        p++;          //下一个学生
        if (p == stu) //到末尾了
        {
            if (m == 2) //队列还剩2个人时退出
            {
                break;
            }
            p = 0; //从第一个开始
            m = 0; //重新统计人数
        }
    }

    for (int i = 0; i < stu; i++)
    {
        if (a[i] != 0)
        {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}
