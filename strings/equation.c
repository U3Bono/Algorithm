#include "../include/strings/equation.h"

void equationMain()
{
    SeqList str;
    initSeqList(&str, sizeof(char));

    printf("Please input the equation:\n");
    getchar();

    char gc;
    while ((gc = getchar()) != '\n')
    {
        insertSeqNode(&str, str.rear + 1, &gc);
    }
    gc = '\0';
    insertSeqNode(&str, str.rear + 1, &gc);

    double result = calculate(str.node);
    destroySeqList(&str);
    printf("The result is %lf.\n", result);
}

double calculate(char *s)
{
    SeqQueue equQueue;  //后缀表达式队列
    LinkStack numStack; //数字栈
    SeqQueue numQueue;  //数字队列
    initSeqQueue(&equQueue, sizeof(char));
    initLinkStack(&numStack, sizeof(double));
    initSeqQueue(&numQueue, sizeof(char));

    postfixEquation(s, &equQueue);

    double sum = 0; //算式的结果
    double number1; //数字栈弹出的数1
    double number2; //数字栈弹出的数2
    char sEnd = '\0';

    char *data = equQueue.list.node;

    for (int i = 0; *(data + i) != '\0'; i++) //字符数组遍历用for(用while会识别编译器自动加入的'\0'，不安全)
    {
        switch (signGrade(*(data + i)))
        {
        case 0: //空格
            if (signGrade(*(data + i - 1)) == 1)
            {
                pushSeqQueue(&numQueue, &sEnd);         //加入结束标志转化为字符串(字符数组无'\0'时空间够编译器会自动加入，不安全)
                number1 = atof(getSeqFront(&numQueue)); //转化成数字
                pushLinkStack(&numStack, &number1);     //将数字压入栈
                initSeqQueue(&numQueue, sizeof(char));  //初始化数字队列
            }
            break;
        case 1:                                  //数字
            pushSeqQueue(&numQueue, (data + i)); //放入数组队列
            break;
        case 3:                                         //+、-运算符
        case 4:                                         //*、/运算符
            number1 = *(double *)getLinkTop(&numStack); //弹出栈顶两个数
            popLinkStack(&numStack);
            number2 = *(double *)getLinkTop(&numStack);
            popLinkStack(&numStack);
            switch (*(data + i))
            {
            case '+':
                sum = number2 + number1;
                break;
            case '-':
                sum = number2 - number1;
                break;
            case '*':
                sum = number2 * number1;
                break;
            case '/':
                sum = number2 / number1;
                break;
            default:
                printf("Input error(1)!\n");
                exit(0);
            }
            pushLinkStack(&numStack, &sum); //结果压入栈
        default:
            break;
        }
    }

    sum = *(double *)getLinkTop(&numStack);

    destroySeqQueue(&equQueue);
    destroyLinkStack(&numStack);
    destroySeqQueue(&numQueue);
    return sum;
}

void postfixEquation(char *s, SeqQueue *seqQueue)
{
    LinkStack signStack; //放符号的栈
    initLinkStack(&signStack, sizeof(char));
    char c;           //取出的字符
    int sg;           //字符的弹出等级
    char space = ' '; //空格符号，表示数字边界
    char zero = '0';  //数字0
    char *stackT;     //符号栈顶点
    int numSum = 0;   //数字个数
    int sgSum = 0;    //运算符个数
    int i;            //字符串元素下标

    for (i = 0; *(s + i) != '\0'; i++)
    {
        c = *(s + i);      //取出字符
        sg = signGrade(c); //判断字符等级
        if (sg == 0)       //空格忽略
        {
            continue;
        }
        if ((i == 0 && c != '-') && (i == 0 && c != '(') && (i == 0 && sg != 0) && (sg == -1)) //格式错误直接返回
        {
            printf("Input error(2)!\n");
            return;
        }

        if (sg == 1) //是数字直接放入队列
        {
            if (signGrade(*(s + i + 1)) != 1) //数字结束统计字符个数
            {
                numSum++;
            }
            pushSeqQueue(seqQueue, &c);
        }
        else
        {
            if (c == '-' || c == '+') //判断是正负号还是运算符
            {
                if (i == 0) //第一位必是正负号
                {
                    pushSeqQueue(seqQueue, &zero);
                    numSum++;
                }
                else
                {
                    char f = ' ';
                    for (int j = 1; f == ' '; j++) //向前找到第一个非空格字符
                    {
                        if (j == i + 1) //越界了
                        {
                            printf("Over limit!\n");
                            break;
                        }
                        f = *(s + i - j);
                    }
                    if (f == '(') //是括号证明是正负号
                    {
                        pushSeqQueue(seqQueue, &zero);
                        numSum++;
                    }
                    else if (signGrade(f) != 1 && f != ')') //其他符号
                    {
                        printf("Input error(3)!\n");
                        return;
                    }
                }
            }

            pushSeqQueue(seqQueue, &space); //放入空格，表示数字边界
            switch (c)
            {
            case ')':                              //反括号
                while (signStack.list.length != 0) //弹出正括号前所有符号
                {
                    stackT = getLinkTop(&signStack);
                    if (*stackT == '(')
                    {
                        break;
                    }
                    pushSeqQueue(seqQueue, stackT);
                    popLinkStack(&signStack);
                }
                if (signStack.list.length == 0) //括号匹配失败
                {
                    printf("Match error(1)!\n");
                    return;
                }
                if (*stackT == '(') //括号匹配成功
                {
                    popLinkStack(&signStack);
                }
                break;
            case '(': //正括号
                if (*(s + i + 1) == ')')
                {
                    printf("Match error(2)!\n");
                    return;
                }
                pushLinkStack(&signStack, &c); //直接压入栈
                break;
            default:
                sgSum++;                           //统计运算符个数
                while (signStack.list.length != 0) //弹出所有符号栈中等级不小于此符号的符号
                {
                    stackT = getLinkTop(&signStack);
                    if (signGrade(*stackT) < sg)
                    {
                        break;
                    }
                    pushSeqQueue(seqQueue, stackT);
                    popLinkStack(&signStack);
                }
                pushLinkStack(&signStack, &c);
                break;
            }
        }
    }
    if (sgSum + 1 != numSum) //数字数量和运算符数量不匹配
    {
        printf("Sign error!");
        printf("sign num:%d, number num:%d\n", sgSum, numSum);
        return;
    }

    pushSeqQueue(seqQueue, &space);    //放入空格，表示数字边界
    while (signStack.list.length != 0) //最后弹出栈中所有符号
    {
        stackT = getLinkTop(&signStack);
        pushSeqQueue(seqQueue, stackT);
        popLinkStack(&signStack);
    }

    c = '\0'; //压入字符结束标志
    pushSeqQueue(seqQueue, &c);
    destroyLinkStack(&signStack);
}

int signGrade(char c)
{
    if ((c < 58 && c > 47) || c == '.')
    {
        return 1;
    }

    switch (c)
    {
    case '(':
        return 2;
    case ')':
        return 2;
    case '+':
        return 3;
    case '-':
        return 3;
    case '*':
        return 4;
    case '/':
        return 4;
    case ' ':
        return 0;
    default:
        return -1;
    }
}