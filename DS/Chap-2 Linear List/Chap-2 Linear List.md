线性表 - Linear List
# 线性表的定义和基本操作
## 定义
**线性表**是由 $n \ge 0$ 个**相同数据类型**的元素组成的**有限**序列。
$n$ 为表长，若 $n = 0$，则称 $L$ 为空表
符号表示：线性表 $L = (a_1,a_2,\cdots.a_i,a_i+1,\cdots,a_n)$

$a_i$ 表示元素线性表中的位序，$a_1$ 表头元素， $a_n$ 表尾元素。
除了表头和表尾均有且仅有一个前驱（前一个）和一个后继（后一个）元素。

**特点：**
- 元素有限
- 元素有**逻辑上**的顺序性，即明确先后顺序
- 每个元素均为数据元素，视作不可分割的单元
- 数据类型相同，各个元素占据相同大小的空间
- 具有抽象性，仅讨论逻辑关系
- 
## 基本操作
`InitList(&L)` 初始化表。构造一个空的表，分配内存空间。
`DestroyList(&L)` 销毁操作。销毁线性表，并释放所占内存。

`ListInsert(&L,i,e)` 插入操作。在第 $i$ 个位置插入指定元素 $e$
`ListDelete(&L,i,&e)` 删除操作。删除第 $i$ 个位置的元素，并用 $e$ 返回删除元素的值

`LocateElem(L,e)` 按**值**查找。找到值为 $e$ 的的元素
`GetElem(L,i)` 按**位**查找，找到第 $i$ 个位置的元素
> 按值查找没说明是找到全部还是第几个 

`Length(L)` 求表长
`PrintList` 输出操作。打印整表
`Empty(L)` 判空操作

> 对数据的操作无非增删改查，加上创建和销毁
**C语言没有引用传递**

# 线性表的顺序表示
## 顺序表的定义
线性表的顺序存储也称顺序表。是用一组**地址连续**的存储单元一次存储线性表中的数据元素，是的逻辑上相邻的元素在物理位置上也相邻。

可以在 **$O(1)$** 时间内直接方位表中任意位置元素。

在高级程序设计语言中，通常使用数组实现线性表

## 顺序表的特点
- 随机访问，在 $O(1)$ 视奸访问第 $i$ 个元素
- 存储密度高，每个节点只需要存储数据元素
- 拓展容量不方便

## 顺序表的实现
### 创建
#### 静态
```cpp
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
```

该顺序表实际大小为 `MaxSize` $\times$ `sizeof(ElemType)`

#### 动态
```cpp
typedef struct
{
    int *data;// 数据
    int MaxSize;// 最大长度
    int length;// 当前长度
}SqList;
// 初始化
void InitList(SqList &L,int Initlength)
{
    L.data = (int*)malloc(Initlength*sizeof(int));
    L.MaxSize = Initlength;
    L.length = 0;
}
// 增加动态数组长度
void IncreaseSize(SqList &L,int len)
{
    int *p = L.data;
    L.data = (int*)malloc((L.MaxSize+len) * sizeof(int));
    for(int i=0;i<L.length;++i)
        L.data[i] = p[i];
    L.MaxSize += len;
    free(p);
}
```

增加长度的复杂度 $O(n)$

### 插入
```cpp
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
```
**复杂度**
- 最好 $O(1)$
- 最坏 $O(n)$
- 平均 $T(n/2) \to O(n)$

### 删除
```cpp
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
```
**复杂度**
- 最好 $O(1)$
- 最坏 $O(n)$
- 平均 $T((n-1)/2) \to O(n)$

### 按位查找
```cpp
int GetElem(SqList L,int i)
{
    if(i < 1 || i > L.length)
        return false;
    return L.data[i-1];
}
```
**复杂度** $O(1)$

### 按值查找
此代码只会找到第一个符合位置的下标
```cpp
int LocateElem(SqList L,int e)
{
    for(int i=0;i<L.length;++i)
    {
        if(L.data[i] == e)  
            return i+1;
    }
    return 0;
}
``` 
> 虽然对结构类型，c无法用`==`比较，但是初试可使用

**复杂度**
- 最好 $O(1)$
- 最坏 $O(n)$
- 平均 $T((n+1)/2) \to O(n)$

# 链表
以链式存储实现线性表统称为链表
## 单链表
每个节点除了存放数据元素外，还要存储指向下一个节点的指针。

**优点：** 不要求大片存储空间，容易改变容量
**缺点：** 不可随机存取，且需要一定空间存放指针

单链表分为

### 创建
```cpp
typedef struct LNode// 单链表类型
{
    int data;// 数据元素
    struct LNode *next;// 指向下一节点的指针
}LNode, *LinkList;// 
```
`*LinkList` 是指向 `struct LNode` 的指针类型

对于 *LNode 和 LinkList 本质没有区别，
只是前者侧重表示节点，后者侧重表示链表。
总之是为了增强可读性

### 初始化
```cpp
// 初始化(无头结点)
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
// 带头结点
bool InitListWithHead(LinkList &L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}
```

对于有/无头结点，区别在于头结点是否存储数据，然后