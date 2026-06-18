#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode
{
    int key;
    int balance;
    AVLNode *lchild, *rchild;
}AVLNode, *AVLTree;

