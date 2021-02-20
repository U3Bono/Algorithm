#include "../../include/container/seqlist.h"

int initSeqList(SeqList *list, int datasize)
{
    list->node = malloc(datasize * INIT_SIZE);
    if (list->node == NULL)
    {
        printf("init failed!list is null.\n");
        return 0;
    }
    list->size = INIT_SIZE;
    list->length = 0;
    list->nodesize = datasize;
    list->front = 0;
    list->rear = 0;
    return 1;
}

int insertSeqNode(SeqList *list, int position, void *data)
{
    if (list == NULL)
    {
        printf("insert failed!list is null.\n");
        return 0;
    }
    if (list->length < position)
    {
        printf("insert failed! (position:%d)\n", position);
        return 0;
    }
    if (list->length == list->size)
    {
        enlargeSeqList(list);
    }

    int distance = (list->front) + position; //实际位置
    distance %= list->size;

    if (list->length == 0) //表为空时，直接插入表头
    {
        list->front = 0;
        list->rear = 0;
        distance = 0;
    }
    else if (position == list->length) //尾部插入
    {
        (list->rear) = distance;
    }
    else if (position == 0) //头部插入
    {
        distance--;
        distance = distance < 0 ? (list->size) - 1 : distance;
        (list->front) = distance;
    }
    else
    {
        (list->rear)++; //尾节点位置
        (list->rear) %= (list->size);
        if ((list->rear) < (list->front)) //循环了
        {
            for (int i = list->rear; i > 0; i--)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i - 1) * (list->nodesize), list->nodesize);
            }
            memcpy((list->node),
                   (list->node) + ((list->size) - 1) * (list->nodesize),
                   list->nodesize);
            for (int i = (list->size) - 1; i > distance; i--)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i - 1) * (list->nodesize), list->nodesize);
            }
        }
        else
        {
            for (int i = list->rear; i > distance; i--)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i - 1) * (list->nodesize), list->nodesize);
            }
        }
    }

    memcpy(list->node + distance * (list->nodesize), data, list->nodesize);
    (list->length)++; //长度+1
    return 1;
}

int delectSeqNode(SeqList *list, int position)
{
    if (list == NULL)
    {
        printf("delect failed!list is null.\n");
        return 0;
    }
    if (list->length - 1 < position)
    {
        printf("delect failed! (position:%d)\n", position);
        return 0;
    }

    int distance = (list->front) + position; //实际位置
    distance %= list->size;

    if (distance == list->rear) //删除尾部
    {
        (list->rear)--;
        (list->rear) = (list->rear) < 0 ? (list->size) - 1 : (list->rear);
    }
    else if (distance == list->front) //删除头部
    {
        (list->front)++;
        (list->front) = (list->front) == (list->size) ? 0 : (list->front);
    }
    else
    {
        if ((list->rear) < (list->front)) //循环了
        {
            for (int i = distance; i < (list->size) - 1; i++)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i + 1) * (list->nodesize), list->nodesize);
            }
            memcpy((list->node) + ((list->size) - 1) * (list->nodesize),
                   (list->node),
                   list->nodesize);
            for (int i = 0; i < list->rear; i++)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i + 1) * (list->nodesize), list->nodesize);
            }
        }
        else
        {
            for (int i = distance; i < list->rear; i++)
            {
                memcpy((list->node) + i * (list->nodesize),
                       (list->node) + (i + 1) * (list->nodesize), list->nodesize);
            }
        }
        (list->rear)--;
        (list->rear) = (list->rear) < 0 ? (list->size) - 1 : (list->rear);
    }
    list->length--; //长度-1

    return 1;
}

void *searchSeqNode(SeqList *list, int position)
{
    if (list == NULL)
    {
        printf("search failed!list is null.\n");
        return NULL;
    }
    if (list->length - 1 < position)
    {
        printf("search failed! (position:%d)\n", position);
        return NULL;
    }

    int distance = (list->front) + position; //实际位置
    distance %= list->size;

    return (list->node) + distance * (list->nodesize);
}

int modifySeqNode(SeqList *list, int position, void *data)
{
    if (list == NULL)
    {
        printf("search failed!list is null.\n");
        return 0;
    }
    if (list->length - 1 < position)
    {
        printf("search failed! (position:%d)\n", position);
        return 0;
    }

    int distance = (list->front) + position; //实际位置
    distance %= list->size;
    memcpy((list->node) + distance * (list->nodesize), data, list->nodesize);

    return 1;
}

int enlargeSeqList(SeqList *list)
{
    if (list == NULL)
    {
        printf("enlarge failed!list is null.\n");
        return 0;
    }

    int size = (list->size) < EX_SIZE_LIMIT ? (list->size) * 2 : (list->size) + EX_SIZE_LIMIT;

    void *newlist = malloc(sizeof(list->nodesize) * size);
    if (newlist == NULL)
    {
        printf("enlarge failed!memory allocation failed.\n");
        return 0;
    }

    if ((list->rear) < (list->front)) //循环了
    {
        int n = (list->size) - (list->front);
        memcpy(newlist, (list->node) + (list->front) * (list->nodesize),
               n * (list->nodesize));
        memcpy(newlist + n * (list->nodesize),
               (list->node), ((list->length) - n) * (list->nodesize));
    }
    else
    {
        memcpy(newlist, (list->node) + (list->front) * (list->nodesize),
               (list->length) * (list->nodesize));
    }

    free(list->node);
    list->node = newlist;
    list->size = size;

    return 1;
}

int destroySeqList(SeqList *list)
{
    if (list == NULL)
    {
        printf("destroy failed!list is null.\n");
        return 0;
    }
    if (list->node == NULL)
    {
        return 0;
    }

    free(list->node);
    initSeqList(list, list->nodesize);

    return 1;
}
