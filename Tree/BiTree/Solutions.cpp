/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-25 18:29:20
 */
#include<stdlib.h>


typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

