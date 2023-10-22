/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-29 21:14:03
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Solutions.cpp"
#define RANDOMNUM 100000
#define MAX 1000



int main(){
    // int arr[RANDOMNUM];
    // clock_t start, end;
    // double cpu_time_used;
    // srand(time(NULL)); // 设置随机数种子
    // start = clock(); // 记录开始时间
    // for (int i = 0; i < RANDOMNUM; i++) {
    //     arr[i] = rand() % MAX; // 生成 0 到 99 之间的随机数
    // }
    // HeapSort(arr, RANDOMNUM);
    // //QuickSort(arr, 0, RANDOMNUM - 1);
    // // SelectSort(arr, RANDOMNUM);
    // end = clock(); // 记录结束时间
    // cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // 计算所用时间（秒）
    // printf("排序1000000个随机数所用时间: %f 秒\n", cpu_time_used);

    int arr[] = {3,6,3,8,1,4,2,4,6,7,4,23,54,67,34,3};
    int i;
    int len = sizeof(arr)/sizeof(arr[0]);
    for(i = 0;i < len;i++){
        printf("%d ",arr[i]);
    }
    InsertSort(arr,len);
    printf("\n");
    for(i = 0;i < len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}