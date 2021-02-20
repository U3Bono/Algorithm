#ifndef _seqqueue_h
#define _seqqueue_h

#include "seqlist.h"

typedef struct
{
    SeqList list;
} SeqQueue;

int initSeqQueue(SeqQueue *queue, int datasize);
int pushSeqQueue(SeqQueue *queue, void *data);
int popSeqQueue(SeqQueue *queue);
void *getSeqFront(SeqQueue *queue);
int destroySeqQueue(SeqQueue *queue);

#endif