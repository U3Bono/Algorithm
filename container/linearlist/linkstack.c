#include "../../include/container/linkstack.h"

int initLinkStack(LinkStack *stack, int datasize)
{
    if (stack == NULL)
    {
        return 0;
    }

    return initLinkList(&(stack->list), datasize);
}

int pushLinkStack(LinkStack *stack, void *data)
{
    if (stack == NULL)
    {
        return 0;
    }
    return addLinkHead(&(stack->list), data);
}

int popLinkStack(LinkStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }
    return delectLinkNode(&(stack->list), stack->list.head);
}

void *getLinkTop(LinkStack *stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    if (stack->list.head == NULL)
    {
        return NULL;
    }
    return stack->list.head->data;
}

int destroyLinkStack(LinkStack *stack)
{
    if (stack == NULL)
    {
        return 0;
    }
    destroyLinkList(&(stack->list));
    return 1;
}
