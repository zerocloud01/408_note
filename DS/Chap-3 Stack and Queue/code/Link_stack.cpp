#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    node *next;
}node, *LinkStack;

bool StackInit(LinkStack stk)
{
    stk = (node*)malloc(sizeof(node));
    if(stk == NULL)
        return false;
    stk->next = NULL;
    return true;
}

bool StackEmpty(LinkStack stk)
{
    return (stk == NULL || stk->next == NULL);
}

bool StackPush(LinkStack stk,int val)
{
    if(stk == NULL)
        return false;
    node *tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
        return false;
    tmp->data = val;
    tmp->next = stk->next;
    stk->next = tmp;
    return true;
}

bool StackPop(LinkStack stk,int &e)
{
    if(StackEmpty(stk))
        return false;
    node *tmp = stk->next;
    e = tmp->data;
    stk->next = tmp->next;
    free(tmp);
    return true;
}

bool StackTop(LinkStack stk,int &top_val)
{
    if(StackEmpty(stk))
        return false;
    top_val = stk->next->data;
    return true;
}