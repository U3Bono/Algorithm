#ifndef _avltree_h
#define _avltree_h

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a > b) ? a : b)
#define HIGHT(AVLTree) ((AVLTree == NULL) ? 0 : AVLTree->hight)

typedef struct AVLNode
{
    int position;
    int hight;
    struct AVLNode *lchild; //左孩子
    struct AVLNode *rchild; //右孩子
    struct AVLNode *parent; //父节点
} AVLNode, *AVLTree;

AVLTree addAVLNode(AVLTree avlTree, int position);
int delectAVLNode(AVLTree avlTree, int position);
AVLNode* searchAVLNode(AVLTree avlTree, int position);
void printfAVLTree(AVLTree avlTree);
int destroyAVLTree(AVLTree avlTree);

AVLTree balanceLeft(AVLTree avlTree);
AVLTree balanceRight(AVLTree avlTree);

#endif