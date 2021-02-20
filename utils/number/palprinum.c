#include "../../include/utils/palprinum.h"

int isPalPriNum(int n)
{
    int isPal;   //是否时回文数
    int bl, bh;  //保存高位和对应低位
    int l = 1;   //数的长度
    int num = 0; //回文数个数
    for (int i = 0; i < n; i++)
    {
        if (i / (int)pow(10, l) != 0)
        {
            l++;
        }
        if (isPrime(i)) //是素数
        {
            isPal = 1;
            for (int j = 1; j < l / 2 + 1; j++)
            {
                bl = i % (int)pow(10, j) / (int)pow(10, j - 1);
                bh = i / (int)pow(10, l - j) % 10;
                if (bl != bh) //不是回文数
                {
                    isPal = 0;
                    break;
                }
            }
            if (isPal)
            {
                printf("%d\t", i);
                num++;
                if (num / 10 != 0)
                {
                    num = 0;
                    return 1;
                }
            }
        }
    }

    return 0;
}
