/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-18 21:03:40
 */
#include<stdio.h>
#define MaxSize 50

typedef int ElemType;


/**
 * @brief 顺序栈
 * 
 */
typedef struct{
    ElemType data[MaxSize];
    int top;//top指针
}sqStack;


/**
 * @brief 初始化栈
 * 
 * @param L 
 * @return true 
 * @return false 
 */
void InitsqStack(sqStack &L){
    L.top = -1;
}


/**
 * @brief 判空
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool StackIsEmpty(sqStack L){
    if (L.top = -1)
    {
        /* code */
        return true;
    }else{
        return false;
    }
}

/**
 * @brief 入栈
 * 
 * @param L 
 * @param x 
 * @return true 
 * @return false 
 */
bool push(sqStack &L,ElemType x){
    if (L.top == MaxSize-1)
    {
        /* code */
        printf("栈已满\n");
        return false;
    }else{
        L.data[++L.top] = x;
        return true;
    }
}


/**
 * @brief 出栈
 * 
 * @param L 
 * @param x  接受栈顶元素
 * @return true 
 * @return false 
 */
bool pop(sqStack &L,ElemType &x)
{
    //判断是否栈空
    if (L.top == -1)
    {
        /* code */
        printf("栈空\n");
        return false;
    }else{
        //先弹出元素后指针自减
        x = L.data[L.top--];
        return true;
    }
    
}

/**
 * @brief Get the Top object
 * 
 * @param L 
 * @param x 
 * @return true 
 * @return false 
 */
bool GetTop(sqStack L, ElemType &x){  
    if(L.top == -1){
        printf("栈空\n");
        return false;
    }else{
        x = L.data[L.top];
        return true;
    }
}
