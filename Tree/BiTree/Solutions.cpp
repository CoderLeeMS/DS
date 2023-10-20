/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-25 18:29:20
 */
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 10


typedef int ElemType;

typedef struct BTNode{
    ElemType data;
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;


typedef struct Stack
{
    /* data */
    BTree data[MaxSize];
    int top;
}Stack;

typedef struct Queue{
    BTree data[MaxSize];
    int front,rear;
}Queue;

void InitStack(Stack &S){
    S.top = -1;
}

bool IsEmpty_Stack(Stack S){
    return S.top == -1;
}

void Push(Stack &S,BTree p){
    S.top++;
    S.data[S.top] = p;
}

BTree Pop(Stack &S){
    BTree p = S.data[S.top];
    S.top--;
    return p;
}

void InitQueue(Queue &Q){
    Q.front = Q.rear = 0;
}

bool IsEmpty_Queue(Queue Q){
    return Q.front == Q.rear;
}

void EnQueue(Queue &Q,BTree p){
    Q.data[Q.front] = p;
    Q.front = (Q.front + 1) %MaxSize;
}

BTree DeQueu(Queue &Q){
    BTree p = Q.data[Q.front];
    Q.front =(Q.front+1) % MaxSize;
    return p;
}

void visit(BTree bt){
    printf("%d",bt->data);
}

/**
 * @brief 
 * 
 * @param bt 
 */
void PreOrder_NoRe(BTree bt){
    Stack S;
    InitStack(S);
    BTree p;
    while(p||IsEmpty_Stack(S)){
        if(p){
            Push(S,p);
            visit(p);
            p = p->lchild;
        }else{
            p = Pop(S);
            p = p->rchild;
        }
    }
}


/**
 * @brief 非递归的先序遍历
 * 
 * @param bt 
 */
void InOrder_NoRe(BTree bt){
    Stack S;
    InitStack(S);
    BTree p;
    while(p||IsEmpty_Stack(S)){
        if(p){
            Push(S,p);
            p = p->lchild;
        }else{
            p = Pop(S);
            visit(p);
            p = p->rchild;
        }
    }
}

/**
 * @brief 层序遍历
 * 
 * @param bt 
 */
void LevelOrder(BTree bt){
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,bt);
    BTNode bt;
    while(IsEmpty_Queue(Q)){
        DeQueu(Q);

    }
}