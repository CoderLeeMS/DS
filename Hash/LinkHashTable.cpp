/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-26 20:50:11
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct ListNode
{
    /* data */
    int key;
    int value;
    struct ListNode* next;
}ListNode;



typedef struct LinkHahsTable{
    ListNode* buckets[MAXSIZE];
}LinkHashTable;



/**
 * @brief 创建结点
 * 
 * @param key 
 * @param value 
 * @return ListNode* 
 */
ListNode * CerateHashNode(int key,int value){
    ListNode * newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief 初始化hash表
 * 
 * @return LinkHahsTable* 
 */
void InitLinkHashTable(LinkHahsTable * table){
    for(int i = 0 ; i < MAXSIZE; i++){
        table->buckets[i] = NULL;
    }
}



/**
 * @brief 哈希函数
 * 
 * @param key 
 * @return int 
 */
int hashfun(int key){
    int value = key % MAXSIZE;
    return value;
}


/**
 * @brief 像hash表中插入结点
 * 
 * @param table 
 * @param key 
 * @param value 
 */
void insert(LinkHahsTable * table,int key,int value){
    int index = hashfun(key);
    ListNode * newNode  = CerateHashNode(key,value);
    if(table->buckets[index]==NULL){
        table->buckets[index] = newNode;
    }else{
        //将新的元素插在表头（头插）
        newNode->next = table->buckets[index];
        table->buckets[index] = newNode;
    }
} 

/**
 * @brief 通过key获取value
 * 
 */
int get(LinkHahsTable * table,int key){
    int index = hashfun(key);
    ListNode *node = table->buckets[index];
    while(node != NULL){
        if(node->key == key){
            return node->value;
        }else{
            node = node->next;
        }
    }
    //键值对不存在
    return -1;
}


