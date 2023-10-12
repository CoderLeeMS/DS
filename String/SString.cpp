/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-05 21:05:50
 */
#include <iostream>
using namespace std;


/**
 * @brief 顺寻串
 * 
 */
#define MaxSize 250
typedef struct{
    char ch[MaxSize];
    int length;
}SString;


/**
 * @brief 暴力字符串匹配
 * 
 * @param S 
 * @param T 
 * @return int 
 */
int Index(SString S,SString T)
{
    int i=1,j=1;
    while (i < S.length && j < T.length)
    { 
        /* code */
        if(S.ch[i] ==T.ch[j])
        {
            i++;
            j++;
        }else{
            i = i-j + 2;
            j = 1;
        }
    }
    if(j > T.length)
    {
        return i - T.length;
    }else{
        return 0;
    }
    
}


/**
 * @brief KMP搜索算法
 * 
 * @param S 
 * @param T 
 * @param next 
 * @return int 
 */
int KMP_Search(SString S,SString T,int next[])
{
    int i = 1,j = 1;
    while(i < S.length && j < T.length)
    {
        //1.当第一个元素不匹配或者元素匹配 ij都自增（j只有在第一次匹配可能出现0）
        if(j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j > T.length)
    {
        return S.length - j;
    }else{
        return 0;
    }
}