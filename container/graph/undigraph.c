#include "../../include/container/undigraph.h"

int searchVertex_U(Undigraph *undigraph, int num);
int pointEdge_U(Undigraph *undigraph, int begin_num, int object_num);

int initUndiGraph(Undigraph *undigraph, int datasize)
{
    if (undigraph == NULL)
    {
        printf("init failed!graph is null.\n");
        return 0;
    }

    undigraph->datasize = datasize;
    initSeqList(&(undigraph->vertex_list), sizeof(Vertex));

    return 1;
}

int addUndiVertex(Undigraph *undigraph, int num, void *data)
{
    if (undigraph == NULL)
    {
        printf("add failed!graph is null.\n");
        return 0;
    }

    if (searchVertex_U(undigraph, num) != -1)
    {
        printf("add failed!number error.\n");
        return 0;
    }

    Vertex new_vertex; //新建一个顶点
    new_vertex.num = num;
    new_vertex.data = malloc(sizeof(undigraph->datasize));
    memcpy(new_vertex.data, data, undigraph->datasize);
    initLinkList(&(new_vertex.edge_list), sizeof(Edge)); //初始化边链表

    return insertSeqNode(&(undigraph->vertex_list), undigraph->vertex_list.length, &new_vertex);
}

int addUndiEdge(Undigraph *undigraph, int begin_num, int object_num, int weight)
{
    if (undigraph == NULL)
    {
        printf("add failed!graph is null.\n");
        return 0;
    }
    if (pointEdge_U(undigraph, begin_num, object_num))
    {
        printf("add failed!number error.\n");
        return 0;
    }

    int begin_position = searchVertex_U(undigraph, begin_num);
    int object_position = searchVertex_U(undigraph, object_num);

    if (begin_position == -1 || object_position == -1)
    {
        printf("add failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
    Vertex *vertex = NULL;

    LinkList *edge_list = NULL;

    vertex = searchSeqNode(vertex_list, begin_position);
    edge_list = &(vertex->edge_list);
    Edge begin_edge;
    begin_edge.weight = weight;
    begin_edge.obj_vertex = searchSeqNode(vertex_list, object_position);
    addLinkTail(edge_list, &begin_edge); //起始顶点边链表加上边

    if (begin_num == object_num)
    {
        return 1;
    }

    vertex = searchSeqNode(vertex_list, object_position);
    edge_list = &(vertex->edge_list);
    Edge object_edge;
    object_edge.weight = weight;
    object_edge.obj_vertex = searchSeqNode(vertex_list, begin_position);
    addLinkTail(edge_list, &object_edge); //目的顶点边链表加上边

    return 1;
}

int delectUndiVertex(Undigraph *undigraph, int num)
{
    if (undigraph == NULL)
    {
        printf("delect failed!graph is null.\n");
        return 0;
    }

    int position = searchVertex_U(undigraph, num); //被删除顶点的位置
    if (position == -1)
    {
        printf("delect failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
    Vertex *vertex = searchSeqNode(vertex_list, position);

    LinkList *edge_list = &(vertex->edge_list); //被删除顶点的边链表
    Edge *edge = NULL;                          //被删顶点的边
    edge_list->p = edge_list->head;
    Node *next = NULL;

    Vertex *obj_vertex = NULL; //目的顶点
    LinkList *obj_list;        //目的顶点的边的链表

    while (edge_list->p != NULL)
    {
        edge = edge_list->p->data;
        obj_vertex = edge->obj_vertex;
        obj_list = &(obj_vertex->edge_list);
        pointEdge_U(undigraph, obj_vertex->num, num);

        delectLinkNode(obj_list, obj_list->p); //删除目的顶点上对应的边

        next = edge_list->p->next;
        delectLinkNode(edge_list, edge_list->p); //删除顶点的边
        edge_list->p = next;
    }

    return delectSeqNode(&(undigraph->vertex_list), position); //删除顶点
}

int delectUndiEdge(Undigraph *undigraph, int begin_num, int object_num)
{
    if (undigraph == NULL)
    {
        printf("delect failed!graph is null.\n");
        return 0;
    }
    if (!pointEdge_U(undigraph, begin_num, object_num))
    {
        printf("delect failed!number error.\n");
        return 0;
    }

    int begin_position = searchVertex_U(undigraph, begin_num);
    int object_position = searchVertex_U(undigraph, object_num);

    SeqList *vertex_list = &(undigraph->vertex_list);
    Vertex *vertex = NULL;

    vertex = searchSeqNode(vertex_list, begin_position);
    LinkList *edge_list = &(vertex->edge_list); //开始顶点上的边
    delectLinkNode(edge_list, edge_list->p);

    if (begin_num == object_num)
    {
        return 1;
    }

    vertex = searchSeqNode(vertex_list, object_position);
    edge_list = &(vertex->edge_list); //目的顶点上的边
    pointEdge_U(undigraph, object_num, begin_num);
    return delectLinkNode(edge_list, edge_list->p);
}

Vertex *searchUndiVertex(Undigraph *undigraph, int num)
{
    if (undigraph == NULL)
    {
        printf("search failed!graph is null.\n");
        return NULL;
    }

    int position = searchVertex_U(undigraph, num);
    if (position == -1)
    {
        printf("search failed!number error.\n");
        return NULL;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);

    return searchSeqNode(vertex_list, position);
}

int modifyUndiVertex(Undigraph *undigraph, int num, Vertex *new_vertex)
{
    if (undigraph == NULL)
    {
        printf("modify failed!graph is null.\n");
        return 0;
    }

    int position = searchVertex_U(undigraph, num);
    if (position == -1)
    {
        printf("modify failed!number error.\n");
        return 0;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
    Vertex *vertex = searchSeqNode(vertex_list, position);

    memcpy(vertex, new_vertex, sizeof(Vertex));
    return 1;
}

int destroyUndiGraph(Undigraph *undigraph)
{
    if (undigraph == NULL)
    {
        printf("destory failed!graph is null.\n");
        return 0;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
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

int searchVertex_U(Undigraph *undigraph, int num)
{
    if (undigraph == NULL)
    {
        return -1;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
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

int pointEdge_U(Undigraph *undigraph, int begin_num, int object_num)
{
    if (undigraph == NULL)
    {
        return 0;
    }

    int begin_position = searchVertex_U(undigraph, begin_num);
    int object_position = searchVertex_U(undigraph, object_num);

    if (begin_position == -1 || object_position == -1)
    {
        return 0;
    }

    SeqList *vertex_list = &(undigraph->vertex_list);
    Vertex *vertex = searchSeqNode(vertex_list, begin_position);
    LinkList *edge_list = &(vertex->edge_list); //起始点的边链表
    edge_list->p = edge_list->head;
    Edge *edge = NULL;
    while (edge_list->p != NULL)
    {
        edge = edge_list->p->data;
        if (edge->obj_vertex->num == object_num)
        {
            return 1;
        }
        edge_list->p = edge_list->p->next;
    }

    return 0;
}