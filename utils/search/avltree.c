#include "../../include/utils/avltree.h"

AVLTree addAVLNode(AVLTree avlTree, int position)
{
    if (avlTree == NULL)
    {
        avlTree = malloc(sizeof(AVLNode));
        avlTree->position = position;
        avlTree->lchild = NULL;
        avlTree->rchild = NULL;
        avlTree->parent = NULL;
    }
    else
    {
        if (avlTree->position > position)
        {
            avlTree->lchild = addAVLNode(avlTree->lchild, position);
            avlTree->lchild->parent = avlTree;
            if (HIGHT(avlTree->lchild) - HIGHT(avlTree->rchild) == 2) //左子树高度增加后不平衡
            {
                avlTree = balanceLeft(avlTree->lchild);
            }
        }
        if (avlTree->position < position)
        {
            avlTree->rchild = addAVLNode(avlTree->rchild, position);
            avlTree->rchild->parent = avlTree;
            if (HIGHT(avlTree->rchild) - HIGHT(avlTree->lchild) == 2) //右子树高度增加后不平衡
            {
                avlTree = balanceRight(avlTree->rchild);
            }
        }
        if (avlTree->position == position) //相同的
        {
            return NULL;
        }
    }
    avlTree->hight = MAX(HIGHT(avlTree->lchild), HIGHT(avlTree->rchild)) + 1;

    return avlTree;
}

int delectAVLNode(AVLTree avlTree, int position)
{
    AVLNode *node = searchAVLNode(avlTree, position);
    if (node == NULL)
    {
        return 0;
    }

    int lc = node->parent == NULL ? -1 : node->parent->lchild == node; //是否是左孩子
    AVLNode *r_node = node->lchild;
    if (r_node == NULL)
    {
        if (node->rchild == NULL)   //叶子节点
        {
            if (lc != -1)
            {
                if (lc)
                {
                    node->parent->lchild = NULL;
                }
                else
                {
                    node->parent->rchild = NULL;
                }
            }
        }
        else
        {
            r_node = node->rchild;
            r_node->parent = node->parent;
            if (lc != -1)
            {
                if (lc)
                {
                    node->parent->lchild = r_node;
                }
                else
                {
                    node->parent->rchild = r_node;
                }
            }
            r_node->hight = MAX(HIGHT(r_node->lchild), HIGHT(r_node->rchild)) + 1;
        }
        free(node);
    }
    else
    {
        if (r_node->rchild == NULL)
        {
            r_node->parent->lchild = NULL; //断开左子树最右节点
        }
        else
        {
            while (r_node->rchild != NULL)
            {
                r_node = r_node->rchild;
            }
            r_node->parent->rchild = NULL; //断开左子树最右节点
        }

        r_node->parent = node->parent; //替换待删除节点
        if (lc != -1)
        {
            if (lc)
            {
                node->parent->lchild = r_node;
            }
            else
            {
                node->parent->rchild = r_node;
            }
        }
        r_node->lchild = node->lchild;
        r_node->lchild->parent = r_node;
        r_node->rchild = node->rchild;
        r_node->rchild->parent = r_node;

        r_node->hight = MAX(HIGHT(r_node->lchild), HIGHT(r_node->rchild)) + 1;
        free(node); //释放待删除节点
    }

    return 1;
}

AVLNode *searchAVLNode(AVLTree avlTree, int position)
{
    if (avlTree != NULL)
    {
        if (avlTree->position == position)
        {
            return avlTree;
        }
        if (avlTree->position > position)
        {
            return searchAVLNode(avlTree->lchild, position);
        }
        if (avlTree->position < position)
        {
            return searchAVLNode(avlTree->rchild, position);
        }
    }
    return NULL;
}

void printfAVLTree(AVLTree avlTree)
{
    if (avlTree->lchild != NULL)
    {
        printfAVLTree(avlTree->lchild);
    }
    if (avlTree != NULL)
    {
        printf("%d ", avlTree->position);
    }
    if (avlTree->rchild != NULL)
    {
        printfAVLTree(avlTree->rchild);
    }
}

int destroyAVLTree(AVLTree avlTree)
{
    if (avlTree->lchild != NULL)
    {
        destroyAVLTree(avlTree->lchild);
    }
    if (avlTree->rchild != NULL)
    {
        destroyAVLTree(avlTree->rchild);
    }
    free(avlTree);
    return 1;
}

AVLTree balanceLeft(AVLTree avlTree)
{
    AVLTree parent = avlTree->parent;
    AVLTree grand = parent->parent;
    int lc = grand == NULL ? -1 : grand->lchild == parent; //是否是左孩子
    if (HIGHT(avlTree->lchild) > HIGHT(avlTree->rchild))
    {
        parent->lchild = avlTree->rchild; //右孩子改为父节点的左孩子
        if (parent->lchild != NULL)
        {
            parent->lchild->parent = parent;
        }
        avlTree->rchild = parent; //本节点右旋
        avlTree->rchild->parent = avlTree;
        avlTree->parent = grand;
        if (lc != -1)
        {
            if (lc)
            {
                grand->lchild = avlTree;
            }
            else
            {
                grand->rchild = avlTree;
            }
        }
        return avlTree;
    }
    else
    {
        parent->lchild = avlTree->rchild->rchild; //右孩子的右孩子改为父节点的左孩子
        parent->lchild->parent = parent;
        avlTree->rchild->rchild = parent; //右孩子左旋成为父节点
        parent->parent = avlTree->rchild;
        if (lc != -1)
        {
            if (lc)
            {
                grand->lchild = avlTree->rchild;
            }
            else
            {
                grand->rchild = avlTree->rchild;
            }
        }
        avlTree->rchild->parent = grand;
        avlTree->parent = avlTree->rchild;
        avlTree->rchild = avlTree->rchild->lchild;
        avlTree->rchild->parent = avlTree;
        avlTree->parent->lchild = avlTree;
        return avlTree->parent;
    }
}

AVLTree balanceRight(AVLTree avlTree)
{
    AVLTree parent = avlTree->parent;
    AVLTree grand = parent->parent;
    int lc = grand == NULL ? -1 : grand->lchild == parent;
    if (HIGHT(avlTree->rchild) > HIGHT(avlTree->lchild))
    {
        parent->rchild = avlTree->lchild; //右孩子改为父节点的左孩子
        if (parent->rchild != NULL)
        {
            parent->rchild->parent = parent;
        }
        avlTree->lchild = parent; //本节点右旋
        avlTree->lchild->parent = avlTree;
        avlTree->parent = grand;
        if (lc != -1)
        {
            if (lc)
            {
                grand->lchild = avlTree;
            }
            else
            {
                grand->rchild = avlTree;
            }
        }
        return avlTree;
    }
    else
    {
        parent->rchild = avlTree->lchild->lchild; //右孩子的右孩子改为父节点的左孩子
        parent->rchild->parent = parent;
        avlTree->lchild->lchild = parent; //右孩子左旋成为父节点
        parent->parent = avlTree->lchild;
        if (lc != -1)
        {
            if (lc)
            {
                grand->lchild = avlTree->lchild;
            }
            else
            {
                grand->rchild = avlTree->lchild;
            }
        }
        avlTree->lchild->parent = grand;
        avlTree->parent = avlTree->lchild;
        avlTree->lchild = avlTree->lchild->rchild;
        avlTree->lchild->parent = avlTree;
        avlTree->parent->rchild = avlTree;
        return avlTree->parent;
    }
}