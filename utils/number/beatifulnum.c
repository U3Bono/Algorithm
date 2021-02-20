#include "../../include/utils/beatifulnum.h"

int isBeautiful(int n, int b)
{
    int m = 0;
    int eb;
    for (int i = b; i > 0; i--)
    {
        eb = n / (int)pow(10, i - 1) % 10;
        m += pow(eb, b);
    }

    return m == n;
}
