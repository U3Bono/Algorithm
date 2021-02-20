#ifndef _linkstack_h
#define _linkstack_h

#include "linklist.h"

typedef struct
{
    LinkList list;
} LinkStack;

int initLinkStack(LinkStack *stack, int datasize);
int pushLinkStack(LinkStack *stack, void *);
int popLinkStack(LinkStack *stack);
void *getLinkTop(LinkStack *stack);
int destroyLinkStack(LinkStack *stack);

#endif