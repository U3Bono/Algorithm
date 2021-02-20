#ifndef _compress_h
#define _compress_h

#include "../container/seqlist.h"
#include "../container/linklist.h"

#define TYPE int

typedef struct
{
    int col;
    TYPE data;
} Matrix_Node;

TYPE *symmetric(TYPE *arr2d, int n);
TYPE *triangle(TYPE *arr2d, int n, int tri_type);
TYPE *claw(TYPE *arr2d, int n);
SeqList *sparse(TYPE *arr2d, int n);
int destroySparseList(SeqList *col_list);

#endif