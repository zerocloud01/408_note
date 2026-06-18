#include <stdio.h>
#include <stdlib.h>

#define END_MARK 999

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化
bool InitList(LinkList &L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 销毁链表
void DestroyList(LinkList &L)
{
    LNode *p;
    while (L != NULL) {
        p = L;
        L = L->next;
        free(p);
    }
}

// 判空
bool Empty(LinkList L)
{
    return (L->next == NULL);
}

// 求长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
// 按位查找：返回第 i 个节点的指针（i=0 为头节点）
LNode *GetElem(LinkList L, int i)
{
    if(i < 0)
        return NULL;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
// 后插
bool InsertNextNode(LNode *p, int e)
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
// 前插
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
// 按位插入
bool ListInsert(LinkList &L, int i, int e)
{
    if(i < 1)
        return false;
    // 找到第 i-1 个节点作为前驱
    return InsertNextNode(GetElem(L,i-1),e);
}
// 删除指定节点
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
// 按位删除
bool ListDelete(LinkList &L, int i, int &e)
{
    if(i < 1)
        return false;
    LNode *p = GetElem(L,i-1); // 找到前驱节点
    if(p == NULL || p->next == NULL)
        return false; // 确保要删的节点存在
    LNode *q = p->next; // q 指向待删节点
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 尾插法建立
LinkList List_TailInsert(LinkList &L)
{
    int x;
    InitList(L); // 确保初始化头节点
    LNode *tmp, *end = L;
    printf("请输入元素（输入 %d 结束）: ", END_MARK);
    scanf("%d", &x);
    while (x != END_MARK)
    {
        tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        end->next = tmp;
        end = tmp;
        scanf("%d", &x);
    }
    end->next = NULL;
    return L;
}
// 打印链表
void PrintList(LinkList L)
{
    LNode *p = L->next;
    printf("链表内容: ");
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
// 01
void DeleteAllThisElem(LinkList L,int x)
{
    LNode *p = L;
    while(p->next != NULL)
    {
        if(p->next->data == x)
        {
            LNode *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
    }
}

// 02
bool DeleteTheMinNode(LinkList L,int x)
{
    LNode *p = L, *min_pre_pos = L;
    if(L->next == NULL)
        return false;
    while(p->next != NULL)
    {
        if(p->next->data < min_pre_pos->next->data) min_pre_pos = p;
        p = p->next;
    }
    LNode *tmp = min_pre_pos->next;
    min_pre_pos->next = tmp->next;
    free(tmp);
    return true;
}
// 03
void ReverseList(LinkList L)
{
    if(L->next == NULL || L->next->next == NULL) return;
    LNode *p1 = L->next, *p2 = L->next->next, *p3 = NULL;
    p1->next = NULL;
    while(p2 != NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2, p2 = p3;
    }
    L->next = p1;
}
// 04
void DeleteAnElem(LinkList L,int s,int t)
{
    LNode *p = L;
    while(p->next != NULL)
    {
        if(p->next->data >= s && p->next->data <= t)
        {
            LNode *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
        p = p->next;
    }
}
// 06
void DivdedIntoTwoList(LinkList L,LinkList A,LinkList B)
{
    LNode *p = L, *pa = A, *pb = B;
    int cnt = 1;
    while(p->next != NULL)
    {
        if(cnt&1)
        {
            pa->next = p->next;
            pa = pa->next;
        }
        else
        {
            pb->next = p->next;
            pb = pb->next;
        }
        cnt ++;
        p = p->next;
    }
}
// 07
void DeleteSameELem(LinkList L)
{
    LNode *p = L->next;
    while(p->next != NULL)
    {
        if(p->data == p->next->data)
        {
            LNode *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
        p = p->next;
    }
}
// 08

int main() {
    LinkList L;
    int e;

    // 建立链表
    List_TailInsert(L);
    PrintList(L);

    // 插入测试
    if(ListInsert(L, 2, 88)) {
        printf("在第2位插入88后: ");
        PrintList(L);
    }

    // 删除测试
    if(ListDelete(L, 1, e)) {
        printf("删除了第1位元素 %d, 剩余: ", e);
        PrintList(L);
    }

    // 销毁
    DestroyList(L);
    printf("链表已销毁。\n");

    return 0;
}