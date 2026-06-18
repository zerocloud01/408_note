#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

BSTNode *BST_Serach(BSTree T,int key)
{
    while(T != NULL && key != T->key)
        T = (key < T->key ? T->lchild : T->rchild);
    return T;
}
// 递归实现，空间复杂度 O(h)
BSTNode *BstSerach2(BSTree &T,int key)
{
    if(T == NULL)
        return NULL;
    if(key == T->key)
        return T;
    else return BstSerach2(key < T->key ? T->lchild : T->rchild,key);
}

bool BST_NewNode(BSTNode *p,int key)
{
    if(p != NULL)
        return false;
    p = (BSTNode*)malloc(sizeof(BSTNode));
    if(p == NULL)   
        return false;
    p->key = key;
    p->lchild = p->rchild = NULL;
}

bool BST_Insert(BSTree T,int k)
{
    while(T != NULL)
    {
        if(T->key == k)
            return false;
        T = (k < T->key ? T->lchild : T->rchild);
    }
    T = BST_Serach(T,k);

    return BST_NewNode(T,k);
}

bool BST_Insert2(BSTree &T,int k)
{
    if(T == NULL)
        return BST_NewNode(T,k);
    else if(k == T->key)
        return 0;
    else return BST_Insert2(k < T->key ? T->lchild : T->rchild,k);
}

bool BST_DeleteNode(BSTree p)
{
    if(p->rchild == NULL)
    {
        BSTNode *tmp = p;
        p = p->lchild;
        free(tmp);
    }
    else if(p->lchild == NULL)
    {
        BSTNode *tmp = p;
        p = p->rchild;
        free(tmp);
    }
    else
    {
        BSTNode *q = p, *s = p->lchild;
        while(s -> rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->key = s->key;
        if(q != p)  q->rchild = s->lchild;
        else    q ->lchild = s->lchild;
    }
}

bool BST_Delete(BSTree T,int k)
{
    if(T == NULL)
        return false;
    else
    {
        
    }
}