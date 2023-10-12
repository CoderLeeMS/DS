/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-18 21:37:00
 */
#include<stdio.h>
#include"SqStack.cpp"

int main(){
    int x;
    sqStack L;
    InitsqStack(L);
    push(L,2);
    GetTop(L,x);
    printf("%d",x);
}