/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-26 21:30:17
 */

#include<stdlib.h>
#include<stdio.h>
#include"LinkHashTable.cpp"


int main(){
    LinkHahsTable table;
    InitLinkHashTable(&table);
    insert(&table,1,38);
    insert(&table,11,25);
    insert(&table,12,79);
    insert(&table,6,88);
    int k1 = get(&table,1);
    int k11 = get(&table,11);
    int k12 = get(&table,12);
    int k6 = get(&table,6);
    printf("k1 = %d\n",k1);
    printf("k11 = %d\n",k11);
    printf("k12 = %d\n",k12);
    printf("k6 = %d\n",k6);
    printf("k7 = %d\n",get(&table,7));
    return 0;
}