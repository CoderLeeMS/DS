#include<stdlib.h>
#include<iostream>
using namespace std;
#define InitSize 5


typedef int ElemType;

/**
 * @brief 动态分配内存实现顺序表，实现扩容
 * 
 */
typedef struct SqList
{
    /* data */
    int * data;     //当前表的长度
    int length,MaxSize; //顺序表的最大长度
}SqList;

/**
 * @brief 初始化顺序表
 * 
 * @param L 
 */
void InitSqlist(SqList &L)
{
    L.data = (int *)malloc(sizeof(SqList)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}


/**
 * @brief 顺序表扩容
 * 
 * @param L 
 * @param inc_memo 
 * @return true 
 * @return false 
 */
bool IncreaseList(SqList &L,int inc_memo)
{
    int * p =L.data;
    L.data = (int *)malloc(sizeof(SqList) * (InitSize + inc_memo));
    for (int i = 0;i < L.length;i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize += inc_memo;
    free(p);
    return true;
}


/**
 * @brief 顺序表的插入--在i处插入e
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListInsert(SqList &L,int i,int e)
{
    //判定i的合法性
    if (i >= L.MaxSize)
    {
        cout<<"插入位置超过表长"<<endl;
        return false;
    }
    if (i < 1 || i > L.length+1)
    {
        cout<<"插入位置应该在0--"<<L.length + 1<<"之间"<<endl;
        return false;
    }
    for (int j = L.length;j >=i;j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    return true;
}

/**
 * @brief 输入插入顺序表
 * 
 * @param L 
 */
bool Listinsert_Generate(SqList &L)
{
    int x;
    scanf("%d",&x);
    int i = 0;
    while (x != 9999)
    {
        if(L.length > L.MaxSize -1)
        {
            cout<<"最多只能插入"<<InitSize<<"个数"<<endl;
            return false;
        }
        L.data[i++] = x;
        scanf("%d",&x);
        L.length++;
    }
    return true;
}

/**
 * @brief 输出顺序表
 * 
 * @param L 
 */
void Output_List(SqList L)
{
    if(L.length == 0)
    {
        printf("线性表长度为零\n");
    }
    for (int i = 0;i < L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
}



/**
 * @brief 删除顺序表中第i个元素，将删除的元素返回
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListDelete(SqList &L,int i,int &e)
{
    if(i > L.length || i < 1)
    {
        printf("index error\n");
        return false;
    }
    e = L.data[i-1];
    for (int j = i-1;j < L.length - 1;j++)
    {
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}