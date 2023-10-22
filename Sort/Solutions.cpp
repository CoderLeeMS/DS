/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-29 20:58:14
 */
#include<stdio.h>

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief 直接插入排序
 * 
 * @param arr 
 * @param len 
 */
void InsertSort(int arr[],int len){
    for(int i = 1;i < len;i++){
        int key  =arr[i];
        int j = i-1;
        while(key < arr[j] && j>= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}





/**
 * @brief 快速排序
 * 
 * @param arr 
 * @param l 
 * @param r 
 */
void QuickSort(int arr[], int l,int r) {
    if (l > r) {
        return;
    }
    int left = l;
    int right = r;
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        if (arr[right] < pivot) {
            arr[left] = arr[right];
        }
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        if (arr[left] > pivot) {
            arr[right] = arr[left];
        }
        if (left >= right) {
            arr[left] = pivot;
        }
    }
    QuickSort(arr, l, right - 1);
    QuickSort(arr, right + 1, r);
}

/**
 * @brief 调整堆
 * 
 * @param arr 
 * @param k 
 * @param len 
 */
void HeadAdjust(int arr[],int k,int len) {
    int largest = k;
    int lson = 2*k+1;
    int rson = 2*k+2;
    if (lson < len && arr[largest] < arr[lson]) {
        largest = lson;
    }
    if (rson < len &&  arr[largest] < arr[rson]) {
        largest = rson;
    }
    if (largest != k)  {
        Swap(arr[k], arr[largest]);
        HeadAdjust(arr, largest, len);
    }
}   


/**
 * @brief Create a Heap object
 * 
 * @param arr 
 * @param len 
 */
void CreateHeap(int arr[],int len) {
    for (int i = len / 2; i >= 0;i-- ) {
        HeadAdjust(arr, i, len);
    }
}


/**
 * @brief 简单选择排序
 * 
 * @param arr 
 * @param len 
 */
void SelectSort(int arr[], int len) {
    int min, i, j;
    for(int i =0;i < len;i++){
        min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] > arr[min]) {
                min = j;
            }
        }
        Swap(arr[i], arr[min]);
    }
}


/**
 * @brief 堆排序
 * 
 * @param arr 
 * @param len 
 */
void HeapSort(int arr[], int len) {
    CreateHeap(arr, len);
    for (int i = len - 1; i > 0; i--) {
        Swap(arr[i], arr[0]);
        HeadAdjust(arr, 0, i);
    }
}
