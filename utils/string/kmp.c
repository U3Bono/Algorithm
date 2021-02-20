#include "../../include/utils/kmp.h"

int kmp_index(char *major, char *pattern)
{
    if (*(pattern + 1) == '\0') //只有一个字符
    {
        for (int i = 0; *(major + i) != '\0'; i++)
        {
            if (*pattern == *(major + i))
            {
                return i;
            }
        }
        return -1;
    }

    SeqQueue next_queue;
    initSeqQueue(&next_queue, sizeof(int));
    get_next_arr(pattern, &next_queue);
    int *next_arr = next_queue.list.node;
    int pattern_length = next_queue.list.length;

    int i = 0; //主串下标
    int j = 0; //模式串下标
    while (*(major + i) != '\0' && *(pattern + j) != '\0')
    {
        if (*(pattern + j) == *(major + i)) //字符匹配成功，模式串前移
        {
            j++;
            i++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = *(next_arr + j); //失败则退到next值
        }
    }

    destroySeqQueue(&next_queue);
    if (*(pattern + j) == '\0') //字符串匹配成功
    {
        return i - pattern_length;
    }
    else
    {
        return -1;
    }
}

void get_next_arr(char *pattern, SeqQueue *next_queue)
{
    int a; //next值
    int *next_arr = next_queue->list.node;

    a = 0;
    pushSeqQueue(next_queue, &a);
    a = 0;
    pushSeqQueue(next_queue, &a);

    int i, j;
    for (i = 2; *(pattern + i) != '\0'; i++) //模式串下标
    {
        j = *(next_arr + i - 1); //前一个字符的next下标，主串当前字符前的字符串，模式串为上一个字符next值及之前字符的字符串
        while (j != 0)
        {
            if (*(pattern + j) == *(pattern + i - 1)) //前一个字符和next值匹配上
            {
                a = (j + 1);
                break;
            }
            else
            {
                j = *(next_arr + j); //失败则退到next值
            }
        }
        if (j == 0) //回溯第一个数时能匹配为1，不能匹配为0
        {
            a = *pattern == *(pattern + i - 1) ? 1 : 0;
        }
        pushSeqQueue(next_queue, &a);
    }
}