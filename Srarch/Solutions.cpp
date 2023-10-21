/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-10-20 23:42:07
 */


/**
 * @brief 调整堆----大根堆
 * 
 * @param A 
 * @param k 
 * @param len 
 */
void HeapAdjust(int A[],int k,int len){//从A[k]喀什调整直到叶子节点
    for(int i = k*2;i < len;i = i*2){
        A[0] = A[k];
        if(i < len && A[i] < A[i+1]){
            i++;
        }
        if(A[0] > A[i]){
            break;
        }else{
            A[k] = A[i];//将小的结点向上移动
            k = i;
        }
        A[k] = A[0];
    }
}

/**
 * @brief 交换
 * 
 * @param a 
 * @param b 
 */
void Swap(int &a,int &b){
    int temp = a;
    b = a;
    a = temp;
}   

/**
 * @brief Create a Heap object
 * 
 * @param A 
 * @param len 
 */
void CreateHeap(int A[],int len){
    for(int i = len/2;i > 1;i--){
        HeapAdjust(A,i,len);
    }
}
