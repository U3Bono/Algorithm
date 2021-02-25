#include "../include/strings/swapletter.h"

void swap_letter(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        printf("string error!\n");
        return;
    }
    int p1 = -1, p2 = -1;
    int l1 = 0, l2 = 0;
    for (int i = 0; *(s1 + i) != '\0'; i++)
    {
        if (*(s1 + i) == 'A')
        {
            if (i == 0 | *(s1 + i - 1) == ' ') //A开头的单词
            {
                p1 = i; //记录开始位置
                do
                {
                    l1++; //记录长度
                } while (*(s1 + i + l1) != ' ' && *(s1 + i + l1) != '\0');
            }
        }
        if (*(s1 + i) == 'N')
        {
            if (*(s1 + i + 1) == ' ' || *(s1 + i + 1) == '\0') //N结尾的单词
            {
                do
                {
                    l2++; //记录开始位置
                } while (*(s1 + i - l2) != ' ' && i != l2);
                p2 = i - l2 + 1; //记录长度
            }
        }
    }
    if (l1 == 0 || l2 == 0) //没有A开头或N结尾的单词
    {
        printf("string error!\n");
        return;
    }

    int i, j, k;
    for (int i = 0, j = 0; *(s1 + i) != '\0'; i++, j++)
    {
        if (i == p1)
        {
            for (k = p2; *(s1 + k) != ' ' && *(s1 + k) != '\0'; k++, j++) //将s1中N结尾的单词复制到s2
            {
                *(s2 + j) = *(s1 + k);
            }
            i += l1; //s1跳过A开头的单词
        }
        else if (i == p2)
        {
            for (k = p1; *(s1 + k) != ' ' && *(s1 + k) != '\0'; k++, j++) //将s1中A开头的单词复制到s2
            {
                *(s2 + j) = *(s1 + k);
            }
            i += l2; //s1跳过N结尾的单词
        }
        else
        {
            *(s2 + j) = *(s1 + i);
        }
    }
}