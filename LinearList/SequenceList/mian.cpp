#include<iostream>
#include"SqList.cpp"
using namespace std;

int main()
{
    SqList  L;
    InitSqlist(L);
    // cout<<sizeof(L)<<endl;
    // bool y = IncreaseList(L,4);
    // if (y)
    // {
    //     cout<<"扩容成功"<<endl;
    // }
    // cout<<"当前的MaxSize为："<<L.MaxSize<<endl;
    // int re = ListInsert(L,1,10);
    // if (re)
    // {
    //     cout<<"插入成功"<<endl;
    // }
    
    // printf("%d",L.data[0]);

    //测试Listinsert_Generate()函数
    bool re = Listinsert_Generate(L);
    if(re)
    {
        printf("successed insert\n");
    }else{
        printf("\n");
    }
    Output_List(L);
    printf("\n");
    int e;
    int i = 3;
    bool judge = ListDelete(L,i,e);
    if(judge)
    {
        cout<<"successed to delete element:"<<e<<endl;
    }else{
        cout<<"fialed to delete the idnex_"<<i<<" element"<<endl;
    }
    Output_List(L);
    return 0;
}