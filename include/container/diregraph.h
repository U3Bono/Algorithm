/*
 *  Directed graph(Orthogonal table):
 *  seq_node data(vertex*) -> link_node data(edge*)
*/

#ifndef _diregraph_h
#define _diregraph_h

#include "linklist.h"
#include "seqlist.h"

typedef struct Vertex
{
    int num;            //顶点编号
    void *data;         //顶点数据
    LinkList edge_list; //边链表，目的顶点
} Vertex;

typedef struct Edge
{
    int weight;         //权
    Vertex *obj_vertex; //目的顶点
    Vertex *beg_vertex; //起始顶点
} Edge;

typedef struct Diregraph
{
    int datasize;        //数据大小
    SeqList vertex_list; //顶点列表
} Diregraph;

int initDireGraph(Diregraph *diregraph, int datasize);
int addDireVertex(Diregraph *diregraph, int num, void *data);
int addDireEdge(Diregraph *diregraph, int begin_num, int object_num, int weight);
int delectDireVertex(Diregraph *diregraph, int num);
int delectDireEdge(Diregraph *diregraph, int begin_num, int object_num);
Vertex *searchDireVertex(Diregraph *diregraph, int num);
int modifyDireVertex(Diregraph *diregraph, int num, Vertex *new_vertex);
int destroyDireGraph(Diregraph *diregraph);

#endif