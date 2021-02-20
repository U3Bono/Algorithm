#ifndef _linkqueue_h
#define _linkqueue_h

#include "linklist.h"

typedef struct
{
    LinkList list;
} LinkQueue;

int initLinkQueue(LinkQueue *queue, int datasize);
int pushLinkQueue(LinkQueue *queue, void *data);
int popLinkQueue(LinkQueue *queue);
void *getLinkFront(LinkQueue *queue);
int destroyLinkQueue(LinkQueue *queue);

#endif