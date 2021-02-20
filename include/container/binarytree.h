/*
 *  Binary tree(Adjacency table):
 *  seq_node data(link*) -> link_node data(tree_node*) -> tree_node data(real data*)
*/

#ifndef _binarytree_h
#define _binarytree_h

#include "linklist.h"
#include "seqlist.h"

#include <math.h>

typedef struct BiTNode
{
    void *data;
    int position;           //本层位置,从0开始
    struct BiTNode *lchild; //左孩子
    struct BiTNode *rchild; //右孩子
    struct BiTNode *parent; //父节点
} BiTNode;

typedef struct
{
    int datasize;        //数据大小
    int storey;          //层数，从1开始
    SeqList storey_list; //层节点列表
} BinTree;

int initBinTree(BinTree *binTree, int datasize);                           //初始化二叉树
int addBinNode(BinTree *binTree, int storey, int position, void *data);    //按序插入一个节点
int delectBinNode(BinTree *binTree, int storey, int position);             //删除一个节点
int delectLastStorey(BinTree *binTree);                                    //删除一最后一行节点
BiTNode *searchBinNode(BinTree *binTree, int storey, int position);        //查询一个节点
int modifyBinNode(BinTree *binTree, int storey, int position, void *data); //修改一个节点
int destroyBinTree(BinTree *binTree);                                      //删除二叉树

int addNodeList(BinTree *binTree);
Node *searchNode_B(BinTree *binTree, int storey, int position);
int pointBefore(LinkList *node_list, int position);

#endif