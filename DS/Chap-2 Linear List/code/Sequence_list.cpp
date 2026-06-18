#include<stdio.h>
#define MaxSize 10// 最大长度
typedef struct
{
    int data[MaxSize];// 静态数组存放元素
    int length;// 当前长度
}SqList;
// 初始化
void InitList(SqList &L)
{
    for(int i=0;i<MaxSize;++i)
        L.data[i] = 0;// 初值设为0
    L.length = 0;// 初始长度为0x
}

bool ListInsert(SqList &L,int i,int e)
{
    // 为保健壮性增加判断
    if(i < 1 || i > L.length+1 || L.length >= MaxSize)
        return false;
    for(int j=L.length;j>=i;--j)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;// 第i个元素下标为i-1
    L.length ++;
    return true;
}

bool ListDelete(SqList &L,int i,int e)
{
    // 为保健壮性增加判断
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j=i;j<L.length;++j)
        L.data[j-1] = L.data[j];
    L.length --;
    return true;
}

int GetElem(SqList L,int i)
{
    if(i < 1 || i > L.length)
        return false;
    return L.data[i-1];
}

int LocateElem(SqList L,int e)
{
    for(int i=0;i<L.length;++i)
    {
        if(L.data[i] == e)  
            return i+1;
    }
    return 0;
}