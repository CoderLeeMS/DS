#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ERROR 0;
#define OK 1;
#define MaxSize 50
//*******************结构体*******************
typedef struct{//邻接矩阵
	char Vex[MaxSize];//顶点表
	int Edge[MaxSize][MaxSize];//邻接矩阵，边表
	int vexnum,arcnum;//顶点数和弧数
}MGraph;

typedef struct ArcNode{//边表结点
	int adjvex;//该弧所指向的顶点的位置
	struct ArcNode *next;//指向下一条弧的指针
	int w;//网的边权值
}ArcNode;

typedef struct VNode{//顶点表节点
	int data;//顶点信息
	ArcNode *first;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxSize];

typedef struct{
	AdjList vertices;//邻接表
	int vexnum,arcnum;//图的顶点数和弧数
}ALGraph;

typedef struct   //栈结构体
{
    int data[MaxSize];
    int top;
}Stack;

typedef struct queue{ //队列结构体
    int front;
    int rear;
    int data[MaxSize];
}Queue;
//*******************辅助函数*******************
bool InitStack(Stack &S){  //初始化栈
    S.top = -1;
    return OK;
}

bool Push(Stack &S,int x){ //入栈
    S.top++;
    S.data[S.top] = x;
    return OK;
}

int Pop(Stack &S){ //出栈
    if(S.top == -1)
        return 0;        
    int p = S.data[S.top];
    S.top--;
    return p;
}

void InitQueue(Queue &Q){//初始化队列
    Q.front = Q.rear = 0;
}

bool IsEmpty(Queue &Q){//队列判空
    return Q.front == Q.rear;
}

void EnQueue(Queue &Q,int s){//入队
	Q.data[Q.rear] = s;
    Q.rear = (Q.rear+1)%MaxSize;
}

int DeQueue(Queue &Q){//出队
	int p = Q.data[Q.front];
    Q.front = (Q.front +1)%MaxSize;
    return p;
}


//*******************练习题1*******************
void InitGraph(MGraph &MG ,int vexsize){//初始化
    MG.arcnum = 0;
    MG.vexnum = vexsize;
    for(int i=0; i<MG.vexnum; i++){
        for(int j=0; j<MG.vexnum; j++)
            MG.Edge[i][j] = 0;
    }
}

void PrintGraph(MGraph MG){//打印
    for(int i=0; i<MG.vexnum; i++){
        for(int j=0; j<MG.vexnum; j++){
            printf("%d ",MG.Edge[i][j]);
        } 
        printf("\n");
    }
    printf("\n");
}

bool Exist(MGraph MG, int u, int v){//边是否存在
    if(u<0 || v<0 || u>MG.vexnum-1 || v>MG.vexnum-1 || MG.Edge[u][v] == 0)
        return false;
    return true;
}

void Insert(MGraph &MG, int u, int v, int w=1){//插入边
    MG.Edge[u][v] = w;
    MG.Edge[v][u] = w;
    MG.arcnum++;
}

void Delete(MGraph &MG, int u, int v){//删除边
    MG.Edge[u][v] = 0;
    MG.Edge[v][u] = 0;
    MG.arcnum--;
}

void InitLGraph(ALGraph &LG, int vexsize){//初始化
    LG.vexnum = vexsize;
    for(int i=0; i<LG.vexnum; i++){
    	LG.vertices[i].data = i;
    	LG.vertices[i].first = NULL;
	}    
}

bool ExistLGraph(ALGraph &LG, int u, int v){//边是否存在
    ArcNode *p = LG.vertices[u].first;
    while(p!=NULL && p->adjvex != v)
        p = p->next;
    if(p)
        return true;
    else
        return false;
}

void InsertLGraph(ALGraph &LG, int u, int v, int w=1){//插入边
    ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = v;
    p->w = w;
    p->next = LG.vertices[u].first;
    LG.vertices[u].first = p;
    LG.arcnum++;
    return;
}

void DeleteLGraph(ALGraph &LG, int u, int v){//删除边
    ArcNode *p, *q;
    p = LG.vertices[u].first, q = NULL;
    while(p != NULL && p->adjvex != v){
        q = p;
        p = p->next;
    }
    if(p == NULL)
    	return;
    if(q == NULL)
        LG.vertices[u].first = p->next;
    else
        q->next = p->next;
    free(p);
}

void PrintLGraph(ALGraph &LG){ //打印
    ArcNode *p;
    for(int i=0; i<LG.vexnum; i++){
        p = LG.vertices[i].first;
        while(p != NULL){
            printf("(%d , %d , %d) ",i,p->adjvex,p->w);
            p = p->next;
        }
        printf("\n");
    }
}

//*******************练习题2*******************
/*
首先，我们需要定义一个访问标志数组visited，用于标记顶点是否已经被访问过。初始化visited数组为0，表示所有顶点都未被访问。

接下来，我们定义一个DFS函数，该函数接受两个参数：图g和要遍历的起始顶点i。

在DFS函数中，首先访问并输出顶点i的数据，然后将visited[i]标记为1，表示该顶点已经被访问。

接着，我们通过访问顶点i的邻接链表，遍历所有与顶点i相邻的顶点。

对于每个未被访问过的邻接顶点j，我们递归调用DFS函数，将j作为起始顶点，以便继续深度遍历。

最后，我们通过遍历图中的所有顶点，保证非连通图的遍历，对于每个未被访问过的顶点v，我们调用DFS函数进行深度优先遍历。
*/
void DFS(int u, int visited[], ALGraph LG){//深度优先
    ArcNode *v;
    printf("%d ", u);
    visited[u] = 1;
    for(v = LG.vertices[u].first; v!=NULL; v = v->next){
        if(visited[v->adjvex] == 0)
            DFS(v->adjvex, visited, LG);
    }
}

void DFSGraph(ALGraph LG){
    int n = LG.vexnum;
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    for(int j=0; j<n; j++){
        if(visited[j] == 0)
            DFS(j,visited,LG);
    }
    printf("\n");
}

/*
首先，创建一个visited数组用于标记顶点是否已被访问。
然后，将初始顶点入栈
接下来，进入循环，每次从栈中取出一个顶点，访问它，并将与之相邻的未访问过的顶点入栈。
直到栈为空，遍历结束。
*/
void DFS1(ALGraph LG, int t){//深度优先非递归
    int n = LG.vexnum;
    ArcNode *v;
    int visited[n];
    Stack S;
    InitStack(S);
    Push(S,t);//将初始顶点入栈
    for(int i=0; i<n; i++)
        visited[i] = 0;
    while(S.top != -1){
        int u = Pop(S);
        printf("%d ",u);
        visited[u]=1;//将其标记为已访问
        for(v=LG.vertices[u].first; v!=NULL; v = v->next){//将与之相邻的未访问过的顶点入栈
        	if(!visited[v->adjvex]){
        		Push(S,v->adjvex);
        		visited[v->adjvex]=1;
			}
		}
    }
    printf("\n");
}
//*******************练习题3*******************
/*
创建一个队列Q，并将起始节点放入队列中。
设置一个数组用来记录访问过的节点。
当队列不为空时，执行以下循环： a. 从队列中取出队头节点Vn。 b. 遍历Vn能够到达的节点Vw：
如果Vw是目标节点，则找到了终点，返回true。
如果Vw是一个合法的节点且未被访问过，则将Vw加入队列Q，并将其标记为已访问。
如果循环结束仍未找到目标节点，则返回false，表示无解。
*/
void BFS(int u,int visited[],ALGraph LG){//宽度优先遍历
    ArcNode *v;
    Queue Q;
    InitQueue(Q);
    printf("%d ",u);
    visited[u] = 1;
    EnQueue(Q,u);
    while(!IsEmpty(Q)){
        int u = DeQueue(Q);
        for(v=LG.vertices[u].first; v!=NULL; v=v->next){
            if(visited[v->adjvex] == 0){
                visited[v->adjvex] = 1;
                printf("%d ",v->adjvex);
                EnQueue(Q,v->adjvex);
            }
        }
    }
}

void BFSGraph(ALGraph LG){
    int n = LG.vexnum;
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    for(int j=0; j<n; j++){
        if(visited[j] == 0)
            BFS(j,visited,LG);
    }
    printf("\n");
}

//*******************练习题4*******************
/*
一个图是否是树？
1、一次dfs可以到达所有顶点
2、边数=顶点数-1
*/
int GetNum(int u, int visited[], ALGraph LG){
    int num =1;
    ArcNode *v;
    printf("%d ", u);
    visited[u] = 1;
    for(v = LG.vertices[u].first; v!=NULL; v = v->next){
        if(visited[v->adjvex] == 0)
            num += GetNum(v->adjvex, visited, LG);
    }
    return num;
}

void IsTree(ALGraph LG){
    int n = LG.vexnum;
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    int num = GetNum(0,visited,LG);
    if(num == LG.vexnum && LG.arcnum == LG.vexnum-1){
        printf("This graph is a tree");
    }else{
        printf("This graph is not a tree");
    }
}

//*******************练习题5*******************
//BFS和DFS皆可
void BFS_i_j(int i, int j, ALGraph LG){
    int n = LG.vexnum;
    int visited[n];
    for(int k=0; k<n; k++)
        visited[k] = 0;
    ArcNode *v;
    Queue Q;
    InitQueue(Q);
    visited[i] = 1;
    EnQueue(Q,i);
    while(!IsEmpty(Q)){
        int u = DeQueue(Q);
        for(v=LG.vertices[u].first; v!=NULL; v=v->next){
            if(visited[v->adjvex] == 0){
                visited[v->adjvex] = 1;
                if(v->adjvex == j){
                    printf("Yes");
                    return;
                }
                EnQueue(Q,v->adjvex);
            }
        }
    }
    printf("No");
}
//*******************练习题6*******************
//递归
void FindPath(ALGraph LG, int u, int v, int path[], int visited[],int d){
	//置visited[u]=1，d++，path[d]=u;若找到u未访问的结点u1，继续下去
	//否则置visited[u]=0并返回
    ArcNode *p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if(u == v){
        for(int i=0; i<=d; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    for(p=LG.vertices[u].first; p;p=p->next){
        if(visited[p->adjvex ==0])
            FindPath(LG,p->adjvex,v,path,visited,d);
    }
    visited[u] = 0;
    //d--;
}

void GetPath(ALGraph LG, int u, int v){
    int n = LG.vexnum;
    int visited[n];
    int path[n];
    int d=-1;
    for(int k=0; k<n; k++){
        visited[k] = 0;
        path[k] = 0;
    }
    FindPath(LG,u,v,path,visited,d);    
}
//*******************测试函数*******************
void test1_1(MGraph &MG){//邻接矩阵测试
	InitGraph(MG,5);
	PrintGraph(MG);
	printf("0-1是否存在边：%d\n",Exist(MG,0,1));
	Insert(MG,0,1);Insert(MG,1,2);Insert(MG,0,2);Insert(MG,0,3);Insert(MG,3,4);
	PrintGraph(MG);
	printf("0-1是否存在边：%d\n",Exist(MG,0,1));
	Delete(MG,0,1);
	PrintGraph(MG);
	printf("0-1是否存在边：%d\n",Exist(MG,0,1));
}

void test1_2(ALGraph LG){
	InitLGraph(LG,5);
	PrintLGraph(LG);
	printf("0-1是否存在边：%d\n",ExistLGraph(LG,0,1));
	InsertLGraph(LG,0,1);InsertLGraph(LG,1,2);InsertLGraph(LG,0,2);InsertLGraph(LG,0,3);InsertLGraph(LG,3,4);
	PrintLGraph(LG);
	printf("0-1是否存在边：%d\n",ExistLGraph(LG,0,1));
	DeleteLGraph(LG,0,1);
	PrintLGraph(LG);
	printf("0-1是否存在边：%d\n",ExistLGraph(LG,0,1));
	
}
void test2and3(ALGraph &LG){
	InitLGraph(LG,5);
	InsertLGraph(LG,0,1);InsertLGraph(LG,1,2);InsertLGraph(LG,0,2);InsertLGraph(LG,0,3);InsertLGraph(LG,3,4);
	PrintLGraph(LG);
	printf("DFS递归：");
	DFSGraph(LG);
	printf("DFS非递归：");
	DFS1(LG,0);
	printf("BFS：");
	BFSGraph(LG);
}

void test4(){
	ALGraph LG;
	InitLGraph(LG,5);
	InsertLGraph(LG,0,1);InsertLGraph(LG,1,2);InsertLGraph(LG,0,2);InsertLGraph(LG,0,3);InsertLGraph(LG,3,4);
	PrintLGraph(LG);
	IsTree(LG);
}

void test5(){
	ALGraph LG;
	InitLGraph(LG,5);
	InsertLGraph(LG,0,1);InsertLGraph(LG,1,2);InsertLGraph(LG,0,2);InsertLGraph(LG,0,3);InsertLGraph(LG,3,4);
	PrintLGraph(LG);
	BFS_i_j(0,2,LG);
}

void test6(){
	ALGraph LG;
	InitLGraph(LG,5);
	InsertLGraph(LG,0,1);InsertLGraph(LG,1,2);InsertLGraph(LG,0,2);
	InsertLGraph(LG,0,3);InsertLGraph(LG,3,4);InsertLGraph(LG,0,4);
	InsertLGraph(LG,2,3);InsertLGraph(LG,2,4);
	PrintLGraph(LG);
	GetPath(LG,0,4);
}
//*******************主函数*******************
int main(){
	//MGraph MG;test1_1(MG);
	//ALGraph LG;test1_2(LG);
	//ALGraph LG;test2and3(LG);
	//test4();
	//test5();
	//test6();
	return 0;
}
