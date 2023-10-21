#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANDOMNUM 100000
#define MAX 1000

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


void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

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


void CreateHeap(int arr[],int len) {
    for (int i = len / 2; i >= 0;i-- ) {
        HeadAdjust(arr, i, len);
    }
}

void HeapSort(int arr[], int len) {
    CreateHeap(arr, len);
    for (int i = len - 1; i > 0; i--) {
        Swap(arr[i], arr[0]);
        HeadAdjust(arr, 0, i);
    }
}

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


int main() {
    int arr[RANDOMNUM];
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL)); // 设置随机数种子
    start = clock(); // 记录开始时间
    for (int i = 0; i < RANDOMNUM; i++) {
        arr[i] = rand() % MAX; // 生成 0 到 99 之间的随机数
    }
    //HeapSort(arr, RANDOMNUM);
    //QuickSort(arr, 0, RANDOMNUM - 1);
    SelectSort(arr, RANDOMNUM);
    end = clock(); // 记录结束时间
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // 计算所用时间（秒）

    printf("生成1000000个随机数所用时间: %f 秒\n", cpu_time_used);
    
    return 0;
}
