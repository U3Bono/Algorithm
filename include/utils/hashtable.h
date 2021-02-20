#ifndef _hashtable_h
#define _hashtable_h

#include "../container/linklist.h"

typedef enum
{
    INT,
    STRING
} ValueType; //支持的散列类型

typedef struct HashNode
{
    int key;
    void *value;
} HashNode;

typedef struct Hashtable
{
    int table_size;                                       //散列表大小
    int value_size;                                       //value值长度
    LinkList *value_list;                                 //value值链表
    int (*fun)(struct Hashtable *hashTable, void *value); //散列函数
} Hashtable;

int initHashTable(Hashtable *hashTable, ValueType valueType, int table_size); //初始化散列表
int inseartHashNode(Hashtable *hashTable, void *value);                       //插入值
int delectHashNode(Hashtable *hashTable, void *value);                        //删除值
void *searchHashNode(Hashtable *hashTable, void *value);                      //查询值在散列表中存放的地址
int destroyHashTable(Hashtable *hashTable);                                   //销毁散列表

Node *searchNode_H(Hashtable *hashTable, void *value);

int hashInt(Hashtable *hashTable, void *value);    //整型散列函数
int hashString(Hashtable *hashTable, void *value); //字符串散列函数

#endif