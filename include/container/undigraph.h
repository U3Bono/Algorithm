/*
 *  Undirected graph(Adjacency table):
 *  seq_node data(vertex*) -> link_node data(edge*)
*/

#ifndef _undigraph_h
#define _undigraph_h

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
} Edge;

typedef struct Undigraph
{
    int datasize;        //数据大小
    SeqList vertex_list; //顶点列表
} Undigraph;

int initUndiGraph(Undigraph *undigraph, int datasize);
int addUndiVertex(Undigraph *undigraph, int num, void *data);
int addUndiEdge(Undigraph *undigraph, int begin_num, int object_num, int weight);
int delectUndiVertex(Undigraph *undigraph, int num);
int delectUndiEdge(Undigraph *undigraph, int begin_num, int object_num);
Vertex *searchUndiVertex(Undigraph *undigraph, int num);
int modifyUndiVertex(Undigraph *undigraph, int num, Vertex *new_vertex);
int destroyUndiGraph(Undigraph *undigraph);

#endif