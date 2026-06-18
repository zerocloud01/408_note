#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
    int data;
    struct Dnode *prior, *next;
}DNode, *DLinkList;

bool InitDList(DLinkList &L)
{
    L = (DNode*)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->prior = L->next = NULL;
    return true;
}

// DNode *GetElem

bool InsertNextDNode(DNode *p)