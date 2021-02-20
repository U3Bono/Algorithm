#include "../../include/utils/num2str.h"

void numConvert(double a, char *s, int length)
{
    int neg = a < 0; //是负数
    if (neg)
    {
        a = -a;
    }
    unsigned long long integerA = (unsigned long long)a; //整数位
    int integerBits = 0;                                 //整数的位数
    int decimalBits = 0;                                 //小数位数
    int decimalZero = 0;                                 //小数位是否是0
    while (integerA != 0)
    {
        integerA /= 10;
        integerBits++;
    }
    if (integerBits < MAX_BIT)
    {
        decimalBits = MAX_BIT - integerBits; //小数位数
        integerA = a * pow(10, decimalBits); //小数位
        decimalZero = integerA % (unsigned long long)pow(10, decimalBits) == 0;
    }

    LinkStack stack; //存放数的栈
    initLinkStack(&stack, sizeof(char));
    int start = 0; //是否开始
    int ib;        //记录每一位数字
    char cb;       //记录每一位字符

    for (int i = 0; i < MAX_BIT; i++)
    {
        ib = integerA % 10;
        if (ib != 0 || (decimalZero && i == decimalBits)) //小数位不为0时从第一个不为0的数开始 或 小数位为0只跳过小数位
        {
            start = 1;
        }
        if (start)
        {
            cb = num2char(ib);
            pushLinkStack(&stack, &cb);
            if (i == decimalBits - 1) //小数压完时
            {
                cb = '.'; //压入浮点
                pushLinkStack(&stack, &cb);
            }
        }
        integerA /= 10;
    }
    if (integerBits == 0) //整数部分为0时压入0
    {
        cb = num2char(0);
        pushLinkStack(&stack, &cb);
    }

    int i = 0;
    while (i < length)
    {
        if (neg && i == 0)
        {
            *(s + i) = '-';
        }
        else
        {
            if (stack.list.length == 0)
            {
                i++;
                break;
            }
            *(s + i) = *(char *)getLinkTop(&stack);
            popLinkStack(&stack);
        }
        i++;
    }
    if (*(s + i - 2) == '.')
    {
        i--;
    }
    *(s + i - 1) = '\0';
    destroyLinkStack(&stack);
}

char num2char(unsigned int n)
{
    if (n > 9 || n < 0)
    {
        return ' ';
    }
    return n + 48;
}