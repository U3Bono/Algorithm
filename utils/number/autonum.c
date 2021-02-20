#include "../../include/utils/autonum.h"

int isAuto(int a)
{
    int n, sq, b;

    b = 1;
    if (a / (int)pow(10, b) != 0)
    {
        {
            b++;
        }
        sq = pow(a, 2);
        if (a == sq % (int)pow(10, b))
        {
            return 1;
        }
    }

    return 0;
}
