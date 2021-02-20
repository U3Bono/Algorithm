#ifndef _seqstack_h
#define _seqstack_h

#include "seqlist.h"

typedef struct
{
    SeqList list;
} SeqStack;

int initSeqStack(SeqStack *stack, int datasize);
int pushSeqStack(SeqStack *stack, void *data);
int popSeqStack(SeqStack *stack);
void *getSeqTop(SeqStack *stack);
int destroySeqStack(SeqStack *stack);

#endif