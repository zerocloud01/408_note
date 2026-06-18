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
// 01
bool DeleteMinElem(SqList L,int &ans)
{
    if(L.length == 0)
        return false;
    int min_pos = 0;
    for(int i=0;i<L.length;++i)
        if(L.data[i] < L.data[min_pos]) min_pos = i;
    ans = L.data[min_pos];
    L.data[min_pos] = L.data[L.length-1];
    L.length --;
    return true;
}

// 02
void swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
bool ListReverse(SqList L)
{
    for(int i=0;i<L.length/2;++i)
        swap(L.data[i],L.data[L.length-i-1]);
}

// 03
void DeleteAllThisElem(SqList L,int e)
{
    int now_end_pos = 0;
    for(int i=0;i<L.length;++i)
    {
        if(L.data[i] != e)
        {
            L.data[now_end_pos] = L.data[i];
            now_end_pos ++;
        }
    }
    L.length = now_end_pos;
}

// 04
void DeleteElemInRange(SqList L,int s,int t)
{
    int cnt = 0;
    for(int i=0;i<L.length;++i)
    {
        if(L.data[i] >= s && L.data[i] <= t)
            cnt ++;
        else
            L.data[i-cnt] = L.data[i];
    }
    L.length -= cnt;
}
// 06
bool InsertEnd(SqList L,int x)
{
    if(L.length >= MaxSize)
        return false;
    L.data[L.length] = x;
    L.length ++;
    return true;
}
bool MergeList(SqList A,SqList B,SqList &C)
{
    if(A.length + B.length > MaxSize)
        return false;
    InitList(C);
    int i = 0, j = 0;
    while(i < A.length && j < B.length)
    {
        if(A.data[i] < B.data[j])
            InsertEnd(C,A.data[i ++]);
        else
            InsertEnd(C,B.data[j ++]);
    }
    while(i < A.length) 
        InsertEnd(C,A.data[i ++]);
    while(j < B.length) 
        InsertEnd(C,B.data[j ++]);
    return true;
}

// 11
int GetMedian(int a[],int b[],int len)
{
    int la = 0,lb = 0,L = len;
    int ma = a[la+(L-1)/2], mb = b[lb+(L-1)/2];
    while(L > 1)
    {
        if(ma == mb)    return ma;
        if(ma < mb)
            la += L/2;
        else
            lb += L/2;
        L = (L+1)>>1;
        ma = a[la+(L-1)/2], mb = b[lb+(L-1)/2];
    }
    return (ma < mb ? ma : mb);
}

int main(void)
{

}