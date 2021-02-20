#include "../../include/container/seqstack.h"

int initSeqStack(SeqStack *stack, int datasize)
{
    if (stack == NULL)
    {
        return 0;
    }

    return initSeqList(&(stack->list), datasize);
}

int pushSeqStack(SeqStack *stack, void *data)
{
    if (stack == NULL)
    {
        return 0;
    }

    return insertSeqNode(&(stack->list), stack->list.length, data);
}

int popSeqStack(SeqStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    return delectSeqNode(&(stack->list), stack->list.length);
}

void *getSeqTop(SeqStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    return (stack->list.node) + (stack->list.rear) * (stack->list.nodesize);
}

int destroySeqStack(SeqStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }

    return destroySeqList(&(stack->list));
}
