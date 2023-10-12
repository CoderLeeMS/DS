/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-29 20:58:14
 */
#define MAXSIZE 50
#include<stdio.h>



typedef struct SqList{
    /* data */
    //顺序表零号位置存放哨兵
    int key[MAXSIZE+1];
    int length;
}SqList;

void InitSqList(SqList *L){
    L->length = 1;
}

void SqListGenerate(SqList * L){
    int x;
    scanf("%d",&x);
    while(x != 9999){
        if (L->length <= MAXSIZE+1){
            /* code */
            L->key[L->length] = x;
            L->length++;
        }
        scanf("%d",&x);   
    }
}   


void Put(SqList L){
    for(int i = 1;i < L.length;i++){
        printf("%d ",L.key[i]);
    }
    
}



/**
 * @brief 插入排序--每一步把待排序的对象查到合适的位置
 * 
 * 
 */
void Insert_Sort(SqList * list){
    int i,j;
    //i=0的位置放哨兵
    for(i = 1;i <= list->length;i++){
        //只有后面的元素比前面的小才会进行移位
        if(list->key[i] < list->key[i-1]){
            //将第i元素放在顺序表第一个位置
            list->key[0] = list->key[i];
            for(j = i - 1;i >= 0 && list->key[j] > list->key[0];j--){
                list->key[j+1] = list->key[j];
            }
        }
        list->key[j+1] = list->key[0];
    }
}


/**
 * @brief 折半插入
 * 
 * @param lsit 
 */
void BInsert_Sort(SqList * lsit){
    
}