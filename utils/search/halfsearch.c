#include "../../include/utils/halfsearch.h"

int halfSearch(int *arr, int size, int a)
{
    int low = 0;
    int high = size - 1;
    int mid;

    if (a == *(arr + high))
    {
        return high;
    }

    while (high != low)
    {
        mid = mid == low + (high - low) / 2 ? high : low + (high - low) / 2;
        if (a < *(arr + mid))
        {
            high = mid;
        }
        else if (a > *(arr + mid))
        {
            low = mid;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}