/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-28 22:16:42
 */
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 10


typedef struct  HashNode
{
    /* data */
    int key;
    int value;
    struct HashNode * next;
}HashNode;


typedef struct  LinkHashTable
{
    /* data */
    HashNode *buckuts[MAXSIZE];
}LinkHashTable,*HashTable;

void InitHashTable(HashTable table){
    for(int i =0; i<MAXSIZE;i++){
        table->buckuts[i] = NULL;
    }
}

int HashFun(int key)
{
    return key % MAXSIZE;
}


HashNode * CreateHashNode(int key,int value){
    HashNode *newnode = (HashNode *)malloc(sizeof(HashNode));
    newnode->key = key;
    newnode->value  = value;
    newnode->next = NULL;
    return newnode;
}   


void Insert(HashTable &table,int key,int value){
    int index = HashFun(key);
}

int main(){
    HashTable table;
    InitHashTable(table);
    return 0;
}