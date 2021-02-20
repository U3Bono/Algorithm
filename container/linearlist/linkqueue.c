#include "../../include/container/linkqueue.h"

int initLinkQueue(LinkQueue *queue, int datasize)
{
    if (queue == NULL)
    {
        return 0;
    }

    return initLinkList(&(queue->list), datasize);
}
int pushLinkQueue(LinkQueue *queue, void *data)
{
    if (queue == NULL)
    {
        return 0;
    }

    return addLinkTail(&(queue->list), data);
}

int popLinkQueue(LinkQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }

    return delectLinkNode(&(queue->list), queue->list.head);
}

void *getLinkFront(LinkQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }

    return queue->list.head->data;
}

int destroyLinkQueue(LinkQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }

    return destroyLinkList(&(queue->list));
}
