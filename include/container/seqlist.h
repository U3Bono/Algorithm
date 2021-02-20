#ifndef _seqlist_h
#define _seqlist_h

#define INIT_SIZE 10        //初始化大小
#define EX_SIZE_LIMIT 10240 //扩容限制

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int size;     //容量
    int length;   //节点个数
    int nodesize; //节点大小
    int front;    //前位置
    int rear;     //后位置
    void *node;   //节点地址
} SeqList;

int initSeqList(SeqList *list, int datasize);               //初始化
int insertSeqNode(SeqList *list, int position, void *data); //按序插入
int delectSeqNode(SeqList *list, int position);             //按序删除
void *searchSeqNode(SeqList *list, int position);           //按序查询
int modifySeqNode(SeqList *list, int position, void *data); //按序修改
int enlargeSeqList(SeqList *list);                          //扩容
int destroySeqList(SeqList *list);                          //销毁

#endif