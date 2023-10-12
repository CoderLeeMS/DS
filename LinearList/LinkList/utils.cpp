#include<stdio.h>
/**
 * @brief 快速排序
 * 
 * @param arr 
 * @param begin 
 * @param end 
 */
void QuickSort(int arr[],int begin,int end)
{
    
    if(begin >= end)
    {
        return;
    }
    int key = arr[begin];
    int i = begin;
    int j = end;
    while (i<j)
    {
        while (i < j && arr[j] >= key)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= key)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;
    QuickSort(arr,begin,i-1);
    QuickSort(arr,i+1,end);
}