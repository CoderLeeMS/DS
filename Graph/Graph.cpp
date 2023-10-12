/*
 * @Descripttion: 图
 * @Author: Daymond
 * @Date: 2023-09-16 20:58:33
 */
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
#define MaxVertextNum 10
#define INIFINITY 65535

typedef char VertextType;
typedef int EdgeType;
/**
 * @brief 邻接矩阵存储
 * 
 */
typedef struct{
    VertextType vertexes[MaxVertextNum];
    EdgeType arc[MaxVertextNum][MaxVertextNum];
    int arcNum,vexNum;
}MGraph;

/**
 * @brief 邻接表存储图
 * 
 */
typedef struct ArcNode//边表节点
{
    /* data */
    int adjvex;
    struct ArcNode *next;
    int w;
}ArcNode;
typedef struct VNode//顶点表结点
{
    /* data */
    VertextType data;
    ArcNode *first;
}VNode, AdjList[MaxVertextNum];
typedef struct 
{
    /* data */
    AdjList vertices;//邻接表
    int vertexNum,ArcNum;//图的边数和顶点数
}ALGraph;


typedef struct  Stack
{
    /* data */
    int data[MaxSize];
    int top;
}Stack;


typedef struct Queue{
    int data[MaxSize];
    int front,rear;
}Queue;
//*******************辅助函数*******************
/**
 * @brief 初始化栈
 * 
 * @param S 
 * @return true 
 * @return false 
 */
bool InitStack(Stack &S){
    S.top = -1;
    return true;
}

void Push(Stack &S,int x){
    S.top++;
    S.data[S.top]  =x;
}

int Pop(Stack &S){
    if(S.top == -1){
        return 0;
    }
    int p = S.data[S.top];
    S.top--;
    return p;
}

bool InitQueue(Queue &Q){
    Q.front = Q.rear = 0;
}

void EnQueue(Queue &Q,int x){
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
}

int DeQueue(Queue &Q){
    return Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
}

bool IsEmpty(Queue &Q){//队列判空
    return Q.front == Q.rear;
}

//*******************练习题1*******************
/**
 * @brief 创建无向图的邻接矩阵
 * 
 */
void CerateMGraph(MGraph *G){
    int i,j,k,w,index;

    printf("请输入图的顶点数和边的数量");
    scanf("%d,%d",&G->vexNum,&G->arcNum);
    //输入顶点信息建立顶点表
    for(i = 0;i < G->vexNum;i++){
        index = i;
        printf("请输入第%d个顶点",index+1);
        scanf("%c",&G->vertexes[i]);
        getchar();
    }
    //初始化邻接矩阵
    for ( i = 0; i < G->vexNum; i++){
        /* code */
        for ( j = 0; j < G->vexNum; j++)
        {
            /* code */
            G->arc[i][j] = 0;
        }
    }
    //输入边的信息，建立邻接矩阵
    for(k = 0;k < G->arcNum;k++){
        printf("请输入(vi,vj)的下标和权重");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

/**
 * @brief 打印矩阵
 * 
 * @param MG 
 */
void printGraph(MGraph MG){//打印矩阵
    for(int i = 0;i < MG.vexNum;i++){
        for(int j =0;j < MG.arcNum;j++){
            printf("%d ",MG.arc[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief 判断边是否存在
 * 
 * @param MG 
 * @param u 
 * @param v 
 * @return true 
 * @return false 
 */
bool Exist(MGraph MG,int u,int v){
    if(u<0||v<0||u>MG.vexNum-1||v>MG.vexNum-1||MG.arc[u][v]==0){
        return false;
    }
    return true;
}

/**
 * @brief 插入边
 * 
 * @param MG 
 * @param u 
 * @param v 
 * @param w 
 */
void Insert(MGraph &MG,int u,int v,int w){
    MG.arc[u][v] = w;
    MG.arc[v][u] = w;
    MG.arcNum++;
}

/**
 * @brief 删除arc
 * 
 * @param MG 
 * @param u 
 * @param v 
 * @param w 
 */
void Delete(MGraph &MG,int u,int v,int w){
    MG.arc[u][v] = 0;
    MG.arc[v][u] = 0;
    MG.arcNum--;
}


/**
 * @brief 初始化邻接表
 * 
 * @param LG 
 * @param vexsize 
 */
void InitALGraph(ALGraph &LG,int vexsize){
    LG.vertexNum = vexsize;
    for(int i = 0;i< LG.vertexNum;i++){
        LG.vertices[i].data = i;
        LG.vertices[i].first = NULL;
    }
}

/**
 * @brief 判断在邻接表中边是否存在
 * 
 * @param LG 
 * @param u 
 * @param v 
 * @return true 
 * @return false 
 */
bool Exist(ALGraph &LG,int u,int v){
    ArcNode *p = LG.vertices[u].first;
    while(p != NULL && p->adjvex != v){
        p = p->next;
    }
    if(p){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief 插入边
 * 
 * @param LG 
 * @param u 
 * @param v 
 * @param w 
 */
void InsertALGraph(ALGraph &LG,int u,int v,int w){
    ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = v;
    p->w = w;
    p->next = LG.vertices[u].first;
    LG.vertices[u].first = p;
    LG.ArcNum++;
}

/**
 * @brief 删除边
 * 
 * @param LG 
 * @param u 
 * @param v 
 */
void DeleteALGrph(ALGraph LG,int u,int v){
    ArcNode *p,*q;
    p = LG.vertices[u].first;
    q = NULL;
    while (p!=NULL && p->adjvex != v)
    {
        /* code */
        p = p->next;
    }
    if(p==NULL){
        return;
    }
    if(q==NULL){
        LG.vertices[u].first = NULL;
    }else{
        q->next = p->next;
    }
}


//*******************深度优先遍历*******************
/**
 * @brief 深度优先
 * 
 * @param u 
 * @param visited 
 * @param LG 
 */
void DFS(int u,int visited[],ALGraph LG){
    ArcNode *v;
    printf("%d",u);
    visited[u] = 1;
    for(v = LG.vertices[u].first;v!=NULL;v=v->next){
        if(visited[v->adjvex==0]){
            DFS(v->adjvex,visited,LG);
        }
    }
}
/**
 * @brief 遍历
 * 
 * @param LG 
 */
void DFSGraph(ALGraph LG){
    int n = LG.vertexNum;
    int visited[n];
    for(int i = 0;i<n;i++){
        visited[i] = 0;
    }
    for(int j = 0;j < n;j++){
        if(visited[j]==0){
            DFS(j,visited,LG);
        }
    }
}

//*******************广度度优先遍历*******************
/**
 * @brief 广度优先
 * 
 * @param u 
 * @param visited 
 * @param LG 
 */
void BFS(int u,int visited[],ALGraph LG){
    ArcNode *v;
    visited[u] = 1;
    printf("%d ",u);
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,u);
    while (!IsEmpty(Q))
    {
        /* code */
        u = DeQueue(Q);
        for(v = LG.vertices[u].first;v!=NULL;v = v->next){
            if (visited[v->adjvex]==0)
            {
                /* code */
                visited[v->adjvex] = 1;
                printf("%d ",v->adjvex);
                EnQueue(Q,v->adjvex);
            }
            
        }
    }
}
/**
 * @brief 遍历
 * 
 * @param LG 
 */
void BFSGraph(ALGraph LG){
    int n = LG.vertexNum;
    int visited[n];
    for(int i=0;i < n;i++){
        visited[i] =0;
    }
    for(int i =0;i < n;i++){
        if(visited[i] == 0){
            BFS(i,visited,LG);
        }
    }
}

//*******************判断图是否是一棵树****************==》1.图连通 2.节点数等于边数加一
/**
 * @brief Get the Num object
 * 看一次BFS或DFS是否能访问所有的元素
 * 
 * @param u 
 * @param visited 
 * @param LG 
 * @return int 
 */
int getNum(int u,int visited[],ALGraph LG){
    int num = 0;
    ArcNode *v;
    printf("%d",u);
    visited[u] = 1;
    for(v = LG.vertices[u].first;v!=NULL;v = v->next){
        if(visited[v->adjvex] == 0){
            num+=getNum(v->adjvex,visited,LG);
        }
    }
    return num;
}

bool IsTree(ALGraph LG){   
    int n = LG.vertexNum;
    int visited[n];
    for(int i  = 0;i<n;i++){
        visited[i] = 0;
    }
    int num = getNum(0,visited,LG);
    if(num == LG.vertexNum && LG.vertexNum - 1 == LG.ArcNum){
        return true;
    }else{
        return false;
    }
}

//*******************判断图中是否存在结点u到v的路径**************
/**
 * @brief 使用广度搜索判断i到j是否有路径
 * 
 * @param i 
 * @param j 
 * @param LG 
 */
void BFS_i_j(int i,int j,ALGraph LG){       
    ArcNode *v;
    int n = LG.vertexNum;
    int visited[n];
    for(int i = 0;i < n;i++){
        visited[n] =0;
    }
    visited[i] = 1;
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,i);
    while (IsEmpty(Q))
    {
        /* code */
        int u = DeQueue(Q);

    }
    
}   