#include "../include/math/multiequation.h"

void multiEquationMain()
{
    printf("**************** Option ****************\n");
    int i = 0;
    int a, b, x;
    printf("0.exit\n1.dichotomy\n2.newtonIM\n3.sectionChord\n");
    scanf("%d", &i);
    switch (i)
    {
    case 0:
        break;
    case 1:
        printf("Please input a,b:");
        scanf("%d,%d", &a, &b);
        printf("The solution is %0.2lf.\n", dichotomy(func, a, b));
        break;
    case 2:
        printf("Please input x:");
        scanf("%d", &x);
        printf("The solution is %0.2lf.\n", newtonIM(x, func, fund));
        break;
    case 3:
        printf("Please input a,b:");
        scanf("%d,%d", &a, &b);
        printf("The solution is %0.2lf.\n", sectionChord(func, a, b));
        break;
    default:
        break;
    }
}

double dichotomy(double (*fp)(double x), int a, int b)
{
    int max, min;

    if (a != b)
    {
        max = a > b ? a : b;
        min = a < b ? a : b;
    }
    else
    {
        max = min = b;
    }

    double mid, fmid;
    int t = 0;
    while (min <= max)
    {
        mid = (max + min) / 2; //坐标中点
        fmid = fp(mid);
        if (fmid < 0)
        {
            min = mid;
        }
        if (fmid > 0)
        {
            max = mid;
        }
        if (fabs(fmid) < EPS)
        {
            return mid;
        }
        t++;
        if (t > 1e8)
        {
            printf("Over times\n");
            exit(0);
        }
    }

    exit(0);
}

double newtonIM(double x, double (*fp1)(double x), double (*fp2)(double x))
{
    double f1, f2;
    int t = 0;
    while (1)
    {
        f1 = fp1(x);
        f2 = fp2(x);

        if (fabs(f1) < EPS)
        {
            return x;
        }
        if (f2 == 0)
        {
            printf("Unsolvale around x!\n");
            exit(0);
        }
        x = x - f1 / f2; //牛顿迭代法公式：x(n + 1) = x(n) - f(n) / f'(n)
        t++;
        if (t > 1e8)
        {
            printf("Over times\n");
            exit(0);
        }
    }
}

double sectionChord(double (*fp)(double x), int a, int b)
{
    double max, min;
    if (a != b)
    {
        max = a > b ? a : b;
        min = a < b ? a : b;
    }
    else
    {
        max = min = b;
    }

    double f1, f2, x, fx;
    while (1)
    {
        f1 = fp(max);
        f2 = fp(min);
        if (f1 * f2 == 0) //解则直接返回，如果两个都是解返回大的一个
        {
            return f1 == 0 ? max : min;
        }
        else if (f1 * f2 > 0) //弦截法要求函数值不同号
        {
            printf("Input error!\n");
            exit(0);
        }
        else
        {
            x = max - (max - min) * f1 / (f1 - f2); //弦与x轴交点
            fx = fp(x);
            if (fabs(fx) < EPS)
            {
                return x;
            }
            if (fx * f1 > 0) //f(x)与f(max)同号
            {
                max = x;
            }
            if (fx * f2 > 0) //f(x)与f(min)同号
            {
                min = x;
            }
        }
    }
}
