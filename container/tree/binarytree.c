#include "../../include/container/binarytree.h"

int initBinTree(BinTree *binTree, int datasize)
{
    if (binTree == NULL)
    {
        printf("init failed!tree is null.\n");
        return 0;
    }
    binTree->datasize = datasize;
    binTree->storey = 0;
    initSeqList(&(binTree->storey_list), sizeof(LinkList)); //初始化层列表
    addNodeList(binTree);                                   //增加第一层链表

    return 1;
}

int addBinNode(BinTree *binTree, int storey, int position, void *data)
{
    if (binTree == NULL)
    {
        printf("add failed!tree is null.\n");
        return 0;
    }
    if (storey > binTree->storey + 1)
    {
        printf("add failed!storey error.\n");
        return 0;
    }
    if (position > pow(2, storey - 1) - 1)
    {
        printf("add failed!position error.\n");
        return 0;
    }

    Node *node = searchNode_B(binTree, storey, position);
    if (node != NULL) //节点位置存在
    {
        printf("add failed!node error.\n");
        return 0;
    }

    LinkList *node_list = binTree->storey_list.node; //层链表
    if (storey == 1)                                 //如果是创建根节点
    {
        BiTNode rootNode; //新建根节点
        rootNode.lchild = NULL;
        rootNode.rchild = NULL;
        rootNode.parent = NULL;
        rootNode.position = position;
        rootNode.data = malloc(binTree->datasize);
        memcpy(rootNode.data, data, binTree->datasize);
        addLinkHead(node_list, &rootNode);
        return 1;
    }

    int parent_storey = storey - 1;     //父节点层数
    int parent_position = position / 2; //父节点位置
    node_list += parent_storey - 1;     //父节点所在层链表
    node = searchNode_B(binTree, parent_storey, parent_position);
    if (node == NULL) //父节点不存在
    {
        printf("add failed!parent node error.\n");
        return 0;
    }
    BiTNode *parent_node = node->data;

    if (storey == binTree->storey + 1) //如果是下一层
    {
        addNodeList(binTree); //增加层链表
    }
    node_list = binTree->storey_list.node;
    node_list += storey - 1; //本节点所在层链表

    BiTNode newNode; //新建树节点
    newNode.lchild = NULL;
    newNode.rchild = NULL;
    newNode.parent = parent_node;
    newNode.position = position;
    newNode.data = malloc(binTree->datasize);
    memcpy(newNode.data, data, binTree->datasize);

    if (position == 0 || node_list->length == 0) //第一个直接头部插入
    {
        addLinkHead(node_list, &newNode);
    }
    else //其他先根据序号找到对应位置
    {
        pointBefore(node_list, position);
        insertAfter(node_list, node_list->p, &newNode);
    }

    if (position % 2 == 0) //左孩子
    {
        parent_node->lchild = node_list->p->data;
    }
    else //右孩子
    {
        parent_node->rchild = node_list->p->data;
    }

    return 1;
}

int delectBinNode(BinTree *binTree, int storey, int position)
{
    if (binTree == NULL)
    {
        printf("delect failed!tree is null.\n");
        return 0;
    }
    if (storey > binTree->storey)
    {
        printf("delect failed!storey is null.\n");
        return 0;
    }

    Node *node = searchNode_B(binTree, storey, position); //本节点
    if (node == NULL)
    {
        printf("delect failed!node error.\n");
        return 0;
    }

    LinkList *node_list = binTree->storey_list.node;
    node_list += storey - 1; //本节点所在层链表

    BiTNode *biTNode = node->data; //本节点
    if (biTNode->lchild != NULL)   //递归删除左子树
    {
        delectBinNode(binTree, storey + 1, biTNode->lchild->position);
    }
    if (biTNode->rchild != NULL) //递归删除右子树
    {
        delectBinNode(binTree, storey + 1, biTNode->rchild->position);
    }

    free(biTNode->data);
    delectLinkNode(node_list, node); //删除本节点
    if (node_list->length == 0)      //如果是本层最后一个节点，删除本层
    {
        delectSeqNode(&(binTree->storey_list), storey - 1);
        (binTree->storey)--;
    }

    return 1;
}

int delectLastStorey(BinTree *binTree)
{
    if (binTree == NULL)
    {
        printf("destroy failed!tree is null.\n");
        return 0;
    }
    LinkList *node_list = binTree->storey_list.node;
    node_list += binTree->storey - 1; //最后一层链表

    node_list->p = node_list->head; //从头节点开始
    BiTNode *biTNode = NULL;
    Node *next = NULL;
    while (node_list->p != NULL)
    {
        biTNode = node_list->p->data; //每个节点的树节点
        next = node_list->p->next;    //下一个节点
        free(biTNode->data);          //删除树节点数据
        free(node_list->p->data);     //删除树节点
        free(node_list->p);           //删除节点
        node_list->p = next;
    }
    (binTree->storey)--;
    return 1;
}

BiTNode *searchBinNode(BinTree *binTree, int storey, int position)
{
    if (binTree == NULL)
    {
        printf("search failed!tree is null.\n");
        return NULL;
    }
    if (storey > binTree->storey)
    {
        printf("search failed!storey error.\n");
        return NULL;
    }

    Node *node = searchNode_B(binTree, storey, position);
    if (node == NULL)
    {
        printf("search failed!node error.\n");
        return NULL;
    }
    return node->data;
}

int modifyBinNode(BinTree *binTree, int storey, int position, void *data)
{
    if (binTree == NULL)
    {
        printf("modify failed!tree is null.\n");
        return 0;
    }
    if (storey > binTree->storey)
    {
        printf("modify failed!storey error.\n");
        return 0;
    }

    Node *node = searchNode_B(binTree, storey, position);
    BiTNode *biTNode = node->data;
    if (node == NULL)
    {
        printf("modify failed!node error.\n");
        return 0;
    }
    memcpy(biTNode->data, data, binTree->datasize);

    return 1;
}

int destroyBinTree(BinTree *binTree)
{
    if (binTree == NULL)
    {
        printf("destroy failed!tree is null.\n");
        return 0;
    }

    while (binTree->storey != 0)
    {
        delectLastStorey(binTree); //删除最后一层
    }

    destroySeqList(&(binTree->storey_list)); //删除层列表
    return 1;
}

int addNodeList(BinTree *binTree)
{
    if (binTree == NULL)
    {
        return 0;
    }
    if (&(binTree->storey_list) == NULL)
    {
        return 0;
    }
    LinkList *node_list = malloc(sizeof(LinkList));
    initLinkList(node_list, sizeof(BiTNode));
    insertSeqNode(&(binTree->storey_list), binTree->storey_list.length, node_list);
    (binTree->storey)++;

    return 1;
}

Node *searchNode_B(BinTree *binTree, int storey, int position)
{
    if (binTree == NULL)
    {
        return NULL;
    }
    LinkList *node_list = binTree->storey_list.node;
    node_list += storey - 1;        //对应层链表
    node_list->p = node_list->head; //指向头节点
    BiTNode *node;                  //树节点
    while (node_list->p != NULL)
    {
        node = node_list->p->data;
        if (node->position == position)
        {
            return node_list->p;
        }
        node_list->p = node_list->p->next;
    }
    return NULL;
}

int pointBefore(LinkList *node_list, int position)
{
    node_list->p = node_list->head;
    BiTNode *node;
    BiTNode *node_next;
    if (node_list->p == NULL)
    {
        return 0;
    }
    while (node_list->p->next != NULL)
    {
        node = node_list->p->data;
        node_next = node_list->p->next->data;
        if (node->position < position && node_next->position > position)
        {
            return 1;
        }
        node_list->p = node_list->p->next;
    }

    node = node_list->p->data;
    return node->position < position;
}
