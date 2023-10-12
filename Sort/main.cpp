/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-29 21:14:03
 */
#include<stdio.h>
#include"Solutions.cpp"

int main(){
    SqList L;
    InitSqList(&L);
    SqListGenerate(&L);
    Put(L);
    Insert_Sort(&L);
    Put(L);
}