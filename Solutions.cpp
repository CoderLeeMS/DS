/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-11-28 19:38:10
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct TNode
{
    int data;
    struct TNode * lchild,*rchild;
    /* data */
}TNode,*BTree;

/**
 * @brief Create a Tree Node object
 * 
 * @param data 
 * @return TNode* 
 */
TNode * CreateTreeNode(int data){
    TNode * newNode = (TNode*)malloc(sizeof(TNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

/**
 * @brief 统计叶子节点
 * 
 * @param T 
 * @return int 
 */
int Count_Leaves(BTree T){
    if(T==NULL){
        return 0;      
    }else if(T->lchild == NULL && T->rchild == NULL){
        return 1;
    }else{
        return Count_Leaves(T->lchild) + Count_Leaves(T->rchild);
    }
}


void visit(TNode * node){
    printf("%d",node->data);
}

void InOrder(BTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

