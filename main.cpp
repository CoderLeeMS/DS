/*
 * @Descripttion: 
 * @Author: Daymond
 * @Date: 2023-11-28 19:45:08
 */
#include<stdio.h>
#include"Solutions.cpp"


int main(){
    BTree tree = CreateTreeNode(1);
    tree->lchild = CreateTreeNode(2);
    tree->rchild = CreateTreeNode(3);
    tree->lchild->lchild = CreateTreeNode(4);
    tree->lchild->lchild->lchild = CreateTreeNode(5);
    tree->lchild->lchild->lchild->rchild = CreateTreeNode(6);
    tree->lchild->lchild->lchild->lchild = CreateTreeNode(7);
    // InOrder(tree);
    int num = Count_Leaves(tree);
    printf("%d",num);

}