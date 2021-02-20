#include "../../include/utils/hashtable.h"

int initHashTable(Hashtable *hashTable, ValueType valueType, int table_size)
{
    if (hashTable == NULL)
    {
        return 0;
    }

    hashTable->table_size = table_size;
    hashTable->value_list = malloc(table_size * sizeof(LinkList));

    switch (valueType)
    {
    case INT:
        hashTable->value_size = sizeof(int);
        hashTable->fun = hashInt;
        for (int i = 0; i < table_size; i++)
        {
            initLinkList((hashTable->value_list) + i, sizeof(int));
        }
        break;
    case STRING:
        hashTable->value_size = sizeof(char *);
        hashTable->fun = hashString;
        for (int i = 0; i < table_size; i++)
        {
            initLinkList((hashTable->value_list) + i, sizeof(char *));
        }
        break;
    default:
        return 0;
    }

    return 1;
}

int inseartHashNode(Hashtable *hashTable, void *value)
{
    if (hashTable == NULL)
    {
        return 0;
    }

    int key = (hashTable->fun)(hashTable, value);
    LinkList *list = hashTable->value_list + key;

    return addLinkTail(list, value);
}

int delectHashNode(Hashtable *hashTable, void *value)
{
    if (hashTable == NULL)
    {
        return 0;
    }

    int key = (hashTable->fun)(hashTable, value);
    LinkList *list = hashTable->value_list + key;

    Node *node = searchNode_H(hashTable, value);

    return delectLinkNode(list, node);
}

void *searchHashNode(Hashtable *hashTable, void *value)
{
    if (hashTable == NULL)
    {
        return NULL;
    }

    Node *node = searchNode_H(hashTable, value);
    if (node == NULL)
    {
        return NULL;
    }

    return node->data;
}

int destroyHashTable(Hashtable *hashTable)
{
    if (hashTable == NULL)
    {
        return 0;
    }
    for (int i = 0; i < hashTable->table_size; i++)
    {
        destroyLinkList((hashTable->value_list) + i);
    }
    free(hashTable->value_list);

    return 1;
}

Node *searchNode_H(Hashtable *hashTable, void *value)
{
    if (hashTable == NULL)
    {
        return NULL;
    }
    int key = (hashTable->fun)(hashTable, value);
    LinkList *list = hashTable->value_list + key;

    list->p = list->head;
    while (list->p != NULL)
    {
        if (memcmp(list->p->data, value, hashTable->value_size) == 0)
        {
            return list->p;
        }
        list->p = list->p->next;
    }

    return NULL;
}

int hashInt(Hashtable *hashTable, void *value)
{
    return *(int *)(value) % hashTable->table_size;
}

int hashString(Hashtable *hashTable, void *value)
{
    char *c = value;
    int sum = 0;
    for (int i = 0; *(c + i) != '\0'; i++)
    {
        sum += *(c + i);
    }
    return sum % hashTable->table_size;
}