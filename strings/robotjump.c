#include "../include/strings/robotjump.h"

void road_input()
{
    int t;           //行数
    char s[STR_LEN]; //轨道
    printf("Please input row:");
    scanf("%d", &t);

    printf("Please input road:\n");
    getchar();
    char c;
    int l = 0;
    for (int i = 0; i < STR_LEN; i++)
    {
        c = getchar();
        if (c != 'R' && c != 'L' && c != '\n')
        {
            printf("Input error.\n");
            return;
        }

        *(s + i) = c == '\n' ? '\0' : c; //记录每个字符串
        l += (c == '\n');                //统计输入行数
        if (l == t)
        {
            break;
        }
    }
    if (l != t) //输入超出范围
    {
        printf("Out of limit.\n");
        return;
    }
    robot_jump(s, t);
}

void robot_jump(char *s, int t)
{
    int d = 0, n = 0;
    char c;
    int l = 0;
    for (int i = 0; i < STR_LEN; i++)
    {
        c = *(s + i);
        switch (c)
        {
        case 'L':
            n++;
            break;
        case 'R':
            d = n > d ? n : d;
            n = 0;
            break;
        case '\0':
            l++;
            printf("%d\n", d + 1);
            d = n = 0;
            break;
        default:
            printf("Jump error!\n");
            return;
        }
        if (l == t)
        {
            break;
        }
    }
    if (l != t) //超出范围
    {
        printf("Jump error!\n");
    }
}