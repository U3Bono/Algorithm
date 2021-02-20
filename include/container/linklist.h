#ifndef _linklist_h
#define _linklist_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    void *data;        //节点数据地址
    struct Node *next; //下一个节点地址
} Node;

typedef struct
{
    int length;   //节点个数
    int datasize; //节点数据大小
    Node *head;   //头节点
    Node *p;      //当前指向节点
    Node *tail;   //尾节点
} LinkList;

int initLinkList(LinkList *list, int datasize);         //初始化
int addLinkHead(LinkList *list, void *data);            //头插
int addLinkTail(LinkList *list, void *data);            //尾插
int insertBefore(LinkList *list, Node *np, void *data); //前插
int insertAfter(LinkList *list, Node *np, void *data);  //后插
int delectLinkNode(LinkList *list, Node *np);           //按位置删除
int pointLinkNode(LinkList *list, Node *np);            //指向指定位置
int pointLinkPrior(LinkList *list, Node *np);           //指向指定前驱
int pointPosition(LinkList *list, int position);        //指向制定序号
int destroyLinkList(LinkList *list);                    //销毁链表

Node *creatLinkNode(LinkList *list); //创建节点

#endif