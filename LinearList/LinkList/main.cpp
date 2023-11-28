/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-05-30 20:37:56
 */
/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-05-30 20:37:56
 */
#include<stdio.h>
#include"LinkList.cpp"


int main()
{
    LinkList L;
    List_TailInsert(L);
    // List_TailInsert(L);
    Output_List(L);
    // List_Revrse(L);
    Delete_p_front(L,4);
    printf("\n");
    // Output_List(L);
    // LinkList l_reverse = List_Revrse(L);
    // printf("\n");
    // Output_List(l_reverse);

    //删除最小值测试
    // Delete_ListMin(L);
    // Output_List(L);

    // List_Order(L);
    // printf("\n");
    Output_List(L);
    return 0;
}