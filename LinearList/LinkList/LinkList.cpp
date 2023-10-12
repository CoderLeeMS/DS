#include<stdlib.h>
#include<stdio.h>
#include"utils.cpp"
#define MaxArraySize 5

typedef int ElemType;

/**
 * @brief 单链表
 * 
 */
typedef struct LNode{
    ElemType data;
    struct LNode * next;
}LNode,*LinkList;


/**
 * @brief 输出链表
 * 
 * @param L 
 */
void Output_List(LinkList L)
{
    L = L->next;
    while (L!=NULL)
    {
        /* code */
        
        printf("%d ",L->data);
        L = L->next;
    }
}



/**
 * @brief 尾插法插入链表
 * 
 * @param L 
 * @return LinkList 
 */
LinkList List_TailInsert(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s,*r = L;
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        /* code */
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x); 
    }
    r->next = NULL;
    return L;
}


/**
 * @brief 头插法建立链表
 * 
 * @param L 
 * @return LinkList 
 */
LinkList List_HeadInsert(LinkList &L)
{
    LNode * s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    // L->data = 0;
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        /* code */
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L; 
    
}


/**
 * @brief 使用头插法将链表逆序
 * 空间复杂度为1
 * @param L 
 * @return LinkList 
 */
LinkList List_Revrse(LinkList &L)
{
    LNode * s,* p = L->next;
    L->next = NULL;
    while (p!=NULL)
    {
        /* code */
        s = p;
        p = p->next;
        s->next = L->next;
        L ->next =  s;
    }
    return L;
}


/**
 * @brief 删除最小的元素（唯一）
 * 
 * @param L 
 */
void Delete_ListMin(LinkList &L)
{
    LNode* pre = L,*p=pre->next;
    LNode* minp = p,*minpre=pre;
    while (p != NULL)
    {
        /* code */
        if(minp->data > p->data)
        {
            minpre = pre;
            minp = p;
        }
        pre = pre->next;
        p = pre->next;
    }
    //删除minp结点
    minpre->next = minp->next;
    free(minp);
}


/**
 * @brief 将链表的升序
 * 将链表转换为数组，在通过数组进行排序，以空间换时间的策略
 * @param L 
 */
void List_Order(LinkList L)
{
    int list_Array[MaxArraySize];
    LNode * s;
    LNode * p = L->next;
    int index = 0;
    int record = 0; 
    while (p!=NULL)
    {
        /* code */
        list_Array[index] = p->data;
        ++index;
        ++record;
        p = p->next;
    }
    
    //通过快速排序将链表中元素排序
    QuickSort(list_Array,0,record-1);
    L->next = NULL;
    //使用头插法将数组、顺序转换为链表
    for(int i = record-1;i >= 0;i--)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = list_Array[i];
        s->next = L->next;
        L->next = s;
    }   
}