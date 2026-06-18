#include<stdio.h>
#include<stdlib.h>

#define MAxSize 50

typedef struct
{
    int data[MAxSize];
    int top;// 栈顶指针
}stack;

void InitStack(stack &stk)
{
    stk.top = -1;
}

bool StackEmpty(stack &stk)
{
    return (stk.top == -1);
}

bool StackPush(stack &stk,int x)
{
    if(stk.top == MAxSize-1)
        return false;
    stk.data[++ stk.top] = x;
    return true;
}

bool StackPop(stack &stk,int &x)
{
    if(stk.top == -1)
        return false;
    x = stk.data[stk.top --];
    return true;
}

bool StackTop(stack &stk,int &x)
{
    if(stk.top == -1)
        return false;
    x = stk.data[stk.top];
    return true;
}

