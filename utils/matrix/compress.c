#include "../../include/utils/compress.h"

TYPE *symmetric(TYPE *arr2d, int n) //对称矩阵
{
    int m_size = (1 + n) * n / 2; //压缩矩阵大小
    TYPE *compress_matrix = malloc(m_size * sizeof(TYPE));
    int p = 0; //压缩矩阵下标

    for (int i = 0; i < n; i++) //行数
    {
        for (int j = 0; j < i + 1; j++) //列数
        {
            memcpy(compress_matrix + p, arr2d + i * n + j, sizeof(TYPE));
            p++;
        }
    }

    return compress_matrix;
}

TYPE *triangle(TYPE *arr2d, int n, int tri_type) //三角矩阵
{
    int m_size = (1 + n) * n / 2 + 1; //压缩矩阵大小
    TYPE *compress_matrix = malloc(m_size * sizeof(TYPE));
    int p = 0; //压缩矩阵下标

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (tri_type) //0.上三角  1.下三角
            {
                memcpy(compress_matrix + p, arr2d + i * n + j, sizeof(TYPE));
            }
            else
            {
                memcpy(compress_matrix + p, arr2d + j * n + i, sizeof(TYPE));
            }
            p++;
        }
    }

    if (tri_type)
    {
        memcpy(compress_matrix + m_size - 1, arr2d + n - 1, sizeof(TYPE));
    }
    else
    {
        memcpy(compress_matrix + m_size - 1, arr2d + n, sizeof(TYPE));
    }

    return compress_matrix;
}

TYPE *claw(TYPE *arr2d, int n) //爪型矩阵
{
    int m_size = 3 * n - 2; //压缩矩阵大小
    TYPE *compress_matrix = malloc(m_size * sizeof(TYPE));
    int p = 0; //压缩矩阵下标

    for (int i = 0; i < n; i++) //行数
    {
        if (i == 0)
        {
            for (int j = 0; j < i + 2; j++) //列数
            {
                memcpy(compress_matrix + p, arr2d + i * n + j, sizeof(TYPE));
                p++;
            }
        }
        else if (i == n - 1)
        {
            for (int j = i - 1; j < n; j++) //列数
            {
                memcpy(compress_matrix + p, arr2d + i * n + j, sizeof(TYPE));
                p++;
            }
        }
        else
        {
            for (int j = i - 1; j < i + 2; j++) //列数
            {
                memcpy(compress_matrix + p, arr2d + i * n + j, sizeof(TYPE));
                p++;
            }
        }
    }

    return compress_matrix;
}

SeqList *sparse(TYPE *arr2d, int n) //稀疏矩阵（十字链表法）
{
    SeqList *col_list = malloc(sizeof(SeqList)); //列数组
    if (col_list == NULL)
    {
        return NULL;
    }
    initSeqList(col_list, sizeof(LinkList));

    for (int i = 0; i < n; i++) //每一行链表加入列数组
    {
        LinkList *rowlist = malloc(sizeof(LinkList));
        if (rowlist == NULL)
        {
            return NULL;
        }
        initLinkList(rowlist, sizeof(Matrix_Node));
        insertSeqNode(col_list, i, rowlist);
    }

    Matrix_Node node;           //每个节点
    LinkList *row_pointer;      //每一行的链表
    for (int i = 0; i < n; i++) //行数
    {
        row_pointer = col_list->node + i;
        for (int j = 0; j < n; j++) //列数
        {
            if (*(arr2d + i * n + j) != 0) //非0元素
            {
                node.col = j;                     //记录列号
                node.data = *(arr2d + i * n + j); //记录数据
                addLinkTail(row_pointer, &node);  //放入行链表
            }
        }
    }

    return col_list;
}

int destroySparseList(SeqList *col_list)
{
    if (col_list == NULL)
    {
        return 0;
    }

    LinkList *row_pointer;
    for (int i = 0; i < col_list->length; i++)
    {
        row_pointer = col_list->node + i;
        if (row_pointer != NULL)
        {
            destroyLinkList(row_pointer);
        }
    }

    destroySeqList(col_list);
    return 1;
}