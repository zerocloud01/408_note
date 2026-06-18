#include<stdio.h>
#include<stdlib.h>
#define END_MARK 999
typedef struct LNode// 单链表类型
{
    int data;// 数据元素
    struct LNode *next;// 指向下一节点的指针
}LNode, *LinkList;// 后者声明LinkList是指向struct LNode 的指针类型
/*
为了区分节点和链表，使用两种别名，但是对于
*LNode 和 LinkList 本质没有区别，
只是前者侧重表示节点，后者侧重表示链表。
总之是为了增强可读性
*/

// 初始化
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
// 按位查找
LNode *GetElem(LinkList L,int i)
{
    if(i < 0)
        return NULL;
    LNode *p = L;
    int j = 1;
    while(p != NULL && j < i)
    {
        p = p->next;
        j ++;
    }
    return p;
}
// 按值查找
LNode *LocateElem(LinkList L,int e)
{
    LNode *p = L;
    while(p != NULL && p->data != e)
        p = p->next;
    return p;
}
// 求长度
int Length(LinkList L)
{
    if(L == NULL)   return 0;
    int len = 0;
    LNode *p = L;
    while(p != NULL)
    {
        p = p->next;
        len ++;
    }
    return len;
}
// 尾插
bool InsertNextNode(LNode *p,int e)
{
    if(p == NULL)
        return false;
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    if(tmp == NULL)
        return false;
    tmp->data = e;
    tmp->next = p->next;
    p->next = tmp;
    return true;
}
// 头插，无节点时无法使用
bool InsertPriorNode(LNode *p,int e)
{
    if(p == NULL)
        return false;
    LNode *tmp = (LNode*)malloc(sizeof(LNode));
    if(tmp == NULL)
        return false;
    tmp->next = p->next;
    p->next = tmp;
    tmp->data = p->data;
    p->data = e;
    return true;
}
// 在第i个位置插入节点
bool ListInsert(LinkList &L,int i,int e)
{
    if(i < 1)
        return false;
    if(i == 1)
    {
        LNode *tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = e;
        tmp->next = L;
        L = tmp;
        return true;
    }
    LNode *p = L;
    int j = 1;
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j ++;
    }
    return InsertNextNode(p,e);
}
// 删除某个节点（无法删除尾节点）
bool DeleteNode(LNode *p,int &e)
{
    if(p == NULL || p->next == NULL)
        return false;
    LNode *tmp = p->next;
    e = p->data;
    p->data = p->next->data;
    p->next = tmp->next;
    free(tmp);
    return true;
}
// 尾删，通过找到 i-1 节点来删除i节点
bool ListDelete(LinkList &L,int i,int &e)
{
    if(i < 1)
        return false;
    if(i == 1)
        return DeleteNode(L,e);
    LNode *p = L;
    int j = 0; 
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j ++;
    }
    if(p == NULL || p->next == NULL)
        return false;
    LNode *q  = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 判空
bool Empty(LinkList L)
{
    return (L == NULL);
}
// 正向简历单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = NULL;
    LNode *tmp, *end = L;
    scanf("%d",&x);
    if(x != END_MARK)
    {
        L = (LNode*)malloc(sizeof(LNode));
        L->data = x;
        L->next = NULL;
        end = L;
    }
    scanf("%d",&x);
    while(x != END_MARK)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        end->next = tmp;
        end = tmp;
        scanf("%d",&x);
    }
    end->next = NULL;
    return L;
}
// 逆向建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *tmp;
    int x;
    L = NULL;
    scanf("%d",&x);
    if(x != END_MARK)
    {
        L = (LNode*)malloc(sizeof(LNode));
        L->data = x;
        L->next = NULL;
    }
    scanf("%d",&x);
    while(x != END_MARK)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        tmp->next = L->next;
        L->next = tmp;
        scanf("%d",&x);
    }
    return L;
}

int main(void)
{

}