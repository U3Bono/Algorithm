#include "../../include/container/diregraph.h"

int searchVertex_D(Diregraph *diregraph, int num);
int pointEdge_D(Diregraph *diregraph, LinkList *edge_list, int begin_num, int object_num);

int initDireGraph(Diregraph *diregraph, int datasize)
{
    if (diregraph == NULL)
    {
        printf("init failed!graph is null.\n");
        return 0;
    }

    diregraph->datasize = datasize;
    initSeqList(&(diregraph->vertex_list), sizeof(Vertex));

    return 1;
}

int addDireVertex(Diregraph *diregraph, int num, void *data)
{
    if (diregraph == NULL)
    {
        printf("add failed!graph is null.\n");
        return 0;
    }

    if (searchVertex_D(diregraph, num) != -1)
    {
        printf("add failed!number error.\n");
        return 0;
    }

    Vertex new_vertex; //新建一个顶点
    new_vertex.num = num;
    new_vertex.data = malloc(sizeof(diregraph->datasize));
    memcpy(new_vertex.data, data, diregraph->datasize);
    initLinkList(&(new_vertex.edge_list), sizeof(Edge)); //初始化边链表

    return insertSeqNode(&(diregraph->vertex_list), diregraph->vertex_list.length, &new_vertex);
}

int addDireEdge(Diregraph *diregraph, int begin_num, int object_num, int weight)
{
    if (diregraph == NULL)
    {
        printf("add failed!graph is null.\n");
        return 0;
    }

    int begin_position = searchVertex_D(diregraph, begin_num);
    int object_position = searchVertex_D(diregraph, object_num);

    if (begin_position == -1 || object_position == -1)
    {
        printf("add failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *vertex_begin = searchSeqNode(vertex_list, begin_position);
    Vertex *vertex_object = searchSeqNode(vertex_list, object_position);

    if (pointEdge_D(diregraph, &(vertex_begin->edge_list), begin_num, object_num))
    {
        printf("add failed!number error.\n");
        return 0;
    }

    LinkList *edge_list = NULL;

    Edge edge;
    edge.weight = weight;
    edge.beg_vertex = vertex_begin;
    edge.obj_vertex = vertex_object;
    edge_list = &(vertex_begin->edge_list);
    addLinkTail(edge_list, &edge); //起始顶点边链表加上边

    if (begin_num == object_num)
    {
        return 1;
    }

    edge_list = &(vertex_object->edge_list);
    addLinkTail(edge_list, &edge); //目的顶点边链表加上边

    return 1;
}

int delectDireVertex(Diregraph *diregraph, int num)
{
    if (diregraph == NULL)
    {
        printf("delect failed!graph is null.\n");
        return 0;
    }

    int position = searchVertex_D(diregraph, num); //被删除顶点的位置
    if (position == -1)
    {
        printf("delect failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *bin_vertex = searchSeqNode(vertex_list, position);

    LinkList *edge_list = &(bin_vertex->edge_list); //开始顶点的边链表
    Edge *edge = NULL;                              //开始顶点的边
    edge_list->p = edge_list->head;
    Node *next = NULL;

    Vertex *obj_vertex = NULL; //开始顶点的目的顶点
    LinkList *obj_list;        //开始顶点的目的顶点的边的链表

    while (edge_list->p != NULL)
    {
        edge = edge_list->p->data;
        obj_vertex = edge->obj_vertex;
        obj_list = &(obj_vertex->edge_list);
        pointEdge_D(diregraph, obj_list, num, obj_vertex->num);
        delectLinkNode(obj_list, obj_list->p); //删除目的顶点上对应的边

        next = edge_list->p->next;
        delectLinkNode(edge_list, edge_list->p); //删除顶点的边
        edge_list->p = next;
    }

    return delectSeqNode(&(diregraph->vertex_list), position); //删除顶点
}

int delectDireEdge(Diregraph *diregraph, int begin_num, int object_num)
{
    if (diregraph == NULL)
    {
        printf("delect failed!graph is null.\n");
        return 0;
    }

    int begin_position = searchVertex_D(diregraph, begin_num);
    int object_position = searchVertex_D(diregraph, object_num);

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *vertex = NULL;
    LinkList *edge_list = NULL;

    vertex = searchSeqNode(vertex_list, begin_position);
    edge_list = &(vertex->edge_list); //开始顶点上的边
    if (!pointEdge_D(diregraph, edge_list, begin_num, object_num))
    {
        printf("delect failed!number error.\n");
        return 0;
    }
    delectLinkNode(edge_list, edge_list->p);

    if (begin_num == object_num)
    {
        return 1;
    }

    vertex = searchSeqNode(vertex_list, object_position);
    edge_list = &(vertex->edge_list); //目的顶点上的边
    if (!pointEdge_D(diregraph, edge_list, begin_num, object_num))
    {
        printf("delect failed!number error.\n");
        return 0;
    }
    delectLinkNode(edge_list, edge_list->p);

    return 1;
}

Vertex *searchDireVertex(Diregraph *diregraph, int num)
{
    if (diregraph == NULL)
    {
        printf("search failed!graph is null.\n");
        return NULL;
    }

    int position = searchVertex_D(diregraph, num);
    if (position == -1)
    {
        printf("search failed!number error.\n");
        return NULL;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);

    return searchSeqNode(vertex_list, position);
}

int modifyDireVertex(Diregraph *diregraph, int num, Vertex *new_vertex)
{
    if (diregraph == NULL)
    {
        printf("modify failed!graph is null.\n");
        return 0;
    }

    int position = searchVertex_D(diregraph, num);
    if (position == -1)
    {
        printf("modify failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *vertex = searchSeqNode(vertex_list, position);

    memcpy(vertex, new_vertex, sizeof(Vertex));
    return 1;
}

int destroyDireGraph(Diregraph *diregraph)
{
    if (diregraph == NULL)
    {
        printf("destory failed!graph is null.\n");
        return 0;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *vertex = NULL;

    for (int i = vertex_list->length - 1; i != 0; i--)
    {
        vertex = searchSeqNode(vertex_list, i);
        destroyLinkList(&(vertex->edge_list));
        free(vertex->data);
    }

    destroySeqList(vertex_list);

    return 1;
}

int searchVertex_D(Diregraph *diregraph, int num)
{
    if (diregraph == NULL)
    {
        return -1;
    }

    SeqList *vertex_list = &(diregraph->vertex_list);
    Vertex *vertex = NULL;
    int i = 0;
    while (i < vertex_list->length)
    {
        vertex = searchSeqNode(vertex_list, i);
        if (vertex->num == num)
        {
            return i;
        }
        i++;
    }

    return -1;
}

int pointEdge_D(Diregraph *diregraph, LinkList *edge_list, int begin_num, int object_num)
{
    if (diregraph == NULL)
    {
        return 0;
    }

    int begin_position = searchVertex_D(diregraph, begin_num);
    int object_position = searchVertex_D(diregraph, object_num);

    if (begin_position == -1 || object_position == -1)
    {
        return 0;
    }

    edge_list->p = edge_list->head;
    Edge *edge = NULL;
    while (edge_list->p != NULL)
    {
        edge = edge_list->p->data;
        if (edge->beg_vertex->num == begin_num && edge->obj_vertex->num == object_num)
        {
            return 1;
        }
        edge_list->p = edge_list->p->next;
    }

    return 0;
}