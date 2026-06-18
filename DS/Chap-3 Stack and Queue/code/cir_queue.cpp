#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int front, back;// 首尾指针
}queue;

bool InitQueue(queue &q)
{
    q.front = q.back = 0;
}

bool QueuePush(queue &q,int val)
{
    if((q.back+1)%MaxSize == q.front) 
        return false;
    q.data[q.back] = val;
    q.back = (q.back+1)%MaxSize;
}

bool QueuePop(queue &q,int &e)
{
        
}