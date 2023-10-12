#include<iostream>
using namespace std;

typedef struct LNode
{
    /* data */
    int data;
    LNode * next;
}LNode,*LinkList;


int main()
{
    LNode x;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(x)<<endl;
    cout<<sizeof(LNode*)<<endl;
    return 0;
}