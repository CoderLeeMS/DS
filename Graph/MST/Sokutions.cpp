/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-09-21 22:09:58
 */
#define MAXVEX 10
#define INFINITY 65535
#include<stdio.h>

typedef struct {
    int verteces[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int arcNum,verNum;
}MGgraph;

/**
 * @brief 生成邻接矩阵表示的图
 * 
 * @param G 
 */
void CreateMGrapg(MGgraph *G){
    int i,j,k;
    printf("输入顶点和边的个数");
    scanf("%d,%d",G->verNum,G->arcNum);
    //初始化矩阵
    for(i = 0;i < MAXVEX; i++)
    {
        for(j = 0;j < MAXVEX;j++)
        {
            G->arc[i][j] = INFINITY;
        }
    }
    //输入节点和边信息
    for(i = 0;i < G->verNum;i++)
    {
        
    }
    
}