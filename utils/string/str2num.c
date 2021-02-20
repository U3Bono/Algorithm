#include "../../include/utils/str2num.h"

double strConvert(char *s)
{
    int part = 1;       //是否是整数部分
    int neg = 0;        //是否是负数
    double sum = 0;     //计算结果
    LinkStack intStack; //整数栈
    initLinkStack(&intStack, sizeof(char));

    int decB; //小数位数
    int bit;  //每一位数
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        if (*(s + i) == ' ') //忽略空格
        {
            continue;
        }
        if (*(s + i) == '-' && i == 0)
        {
            neg = 1;
            continue;
        }
        if (*(s + i) == '.') //到了小数部分
        {
            if (part == 0) //小数部分再遇到小数报错
            {
                printf("Convert error!\n");
                exit(0);
            }
            part = 0;
            decB = 0;
        }
        else
        {
            if (part) //整数部分压入栈
            {
                pushLinkStack(&intStack, (s + i));
            }
            else //小数部分直接计算
            {
                bit = char2int(*(s + i));
                if (bit == -1)
                {
                    printf("Convert error!\n");
                    exit(0);
                }
                sum += bit * pow(10, --decB);
            }
        }
    }

    for (int i = 0; intStack.list.length != 0; i++)
    {
        bit = char2int(*(char *)getLinkTop(&intStack));
        if (bit == -1)
        {
            printf("Convert error!\n");
            exit(0);
        }
        sum += bit * pow(10, i);
        popLinkStack(&intStack);
    }

    return sum * pow(-1, neg);
}

int char2int(char c)
{
    if (c > '9' || c < '0')
    {
        return -1;
    }

    return (c - 48);
}