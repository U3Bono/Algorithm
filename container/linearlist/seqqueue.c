#include "../../include/container/seqqueue.h"

int initSeqQueue(SeqQueue *queue, int datasize)
{
    if (queue == NULL)
    {
        return 0;
    }

    return initSeqList(&(queue->list), datasize);
}
int pushSeqQueue(SeqQueue *queue, void *data)
{
    if (queue == NULL)
    {
        return 0;
    }
    return insertSeqNode(&(queue->list), queue->list.length, data);
}

int popSeqQueue(SeqQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }
    return delectSeqNode(&(queue->list), 0);
}

void *getSeqFront(SeqQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }
    return (queue->list.node) + (queue->list.front) * (queue->list.nodesize);
}

int destroySeqQueue(SeqQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }

    return destroySeqList(&(queue->list));
}
