#include "../../include/container/linklist.h"

int initLinkList(LinkList *list, int datasize)
{
    if (list == NULL)
    {
        printf("init failed!list is null.\n");
        return 0;
    }
    list->length = 0;
    list->datasize = datasize;
    list->head = NULL;
    list->p = NULL;
    list->tail = NULL;

    return 1;
}

int addLinkHead(LinkList *list, void *data)
{
    if (list == NULL)
    {
        printf("add failed!list is null.\n");
        return 0;
    }

    Node *newNode = creatLinkNode(list);
    if (newNode == NULL)
    {
        printf("add failed!memory allocation failed.\n");
        return 0;
    }

    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL)
    {
        list->tail = list->head;
    }

    (list->length)++;

    memcpy(list->head->data, data, list->datasize);
    list->p = list->head;

    return 1;
}

int addLinkTail(LinkList *list, void *data)
{
    if (list == NULL)
    {
        printf("add failed!list is null.\n");
        return 0;
    }

    Node *newNode = creatLinkNode(list);
    if (newNode == NULL)
    {
        printf("add failed!memory allocation failed.\n");
        return 0;
    }

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = list->head;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = list->tail->next;
    }
    list->tail->next = NULL;

    (list->length)++;

    memcpy(list->tail->data, data, list->datasize);
    list->p = list->tail;

    return 1;
}

int insertBefore(LinkList *list, Node *np, void *data)
{
    if (list == NULL)
    {
        printf("insert failed!list is null.\n");
        return 0;
    }
    if (!pointLinkNode(list, np))
    {
        return 0;
    }

    Node *newNode = creatLinkNode(list);
    if (newNode == NULL)
    {
        printf("insert failed!memory allocation failed.\n");
        return 0;
    }

    newNode->next = list->p->next;
    list->p->next = newNode;

    memcpy(newNode->data, list->p->data, list->datasize);

    (list->length)++;

    memcpy(list->p->data, data, list->datasize);

    return 1;
}

int insertAfter(LinkList *list, Node *np, void *data)
{
    if (list == NULL)
    {
        printf("insert failed!list is null.\n");
        return 0;
    }
    if (!pointLinkNode(list, np))
    {
        return 0;
    }

    Node *newNode = creatLinkNode(list);
    if (newNode == 0)
    {
        printf("insert failed!memory allocation failed.\n");
        return 0;
    }

    newNode->next = list->p->next;
    list->p->next = newNode;

    (list->length)++;

    memcpy(list->p->next->data, data, list->datasize);
    list->p = list->p->next;

    return 1;
}

int delectLinkNode(LinkList *list, Node *np)
{
    if (list == NULL)
    {
        printf("delect failed!list is null.\n");
        return 0;
    }
    if (list->head == NULL)
    {
        return 0;
    }
    if (np == list->head)
    {
        list->p = list->head->next;
        free(list->head->data);
        free(list->head);
        list->head = list->p;
    }
    else
    {
        if (!pointLinkPrior(list, np))
        {
            return 0;
        }

        list->p->next = np->next;
        free(np->data);
        free(np);
    }

    (list->length)--;
    if (list->length == 0)
    {
        initLinkList(list, list->datasize);
    }

    return 1;
}

int pointLinkNode(LinkList *list, Node *np)
{
    if (list == NULL)
    {
        printf("point failed!list is null.\n");
        return 0;
    }
    Node *start = list->p;

    do
    {
        if (list->p == np)
        {
            return 1;
        }
        list->p = list->p->next == NULL ? list->head : list->p->next;
    } while (list->p == start);

    return 0;
}

int pointLinkPrior(LinkList *list, Node *np)
{
    if (list == NULL)
    {
        printf("point failed!list is null.\n");
        return 0;
    }
    if (np == list->head)
    {
        return 0;
    }

    list->p = list->head;
    Node *next = list->p->next;
    while (next != NULL)
    {
        if (next == np)
        {
            return 1;
        }
        list->p = next;
        next = next->next;
    }

    return 0;
}

int pointPosition(LinkList *list, int position)
{
    if (list == NULL)
    {
        printf("point failed!list is null.\n");
        return 0;
    }
    if (list->length - 1 < position)
    {
        printf("point failed! (position:%d)\n", position);
        return 0;
    }
    list->p = list->head;
    for (int i = 0; i < position; i++)
    {
        list->p = list->p->next;
    }
    return 1;
}

int destroyLinkList(LinkList *list)
{
    if (list == NULL)
    {
        printf("destroy failed!list is null.\n");
        return 0;
    }

    Node *next = NULL;
    list->p = list->head;
    while (list->p != NULL)
    {
        next = list->p->next;
        free(list->p->data);
        free(list->p);
        list->p = next;
    }
    initLinkList(list, list->datasize);

    return 1;
}

Node *creatLinkNode(LinkList *list)
{
    Node *np = (Node *)malloc(sizeof(Node));
    np->data = malloc(list->datasize);
    return np;
}
