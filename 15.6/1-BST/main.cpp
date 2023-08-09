#include <stdio.h>
#include "stdlib.h"

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *rchild,*lchild;
}BSTNode,*BiTree;

//非递归的创建二叉查找树
int BST_Insert(BiTree &T,KeyType k){
    BiTree TreeNew=(BiTree) calloc(1,sizeof (BSTNode));//新结点申请空间
    TreeNew->key=k;//把值放入
    if(NULL==T)//树为空，新结点作为树的根
    {
        T=TreeNew;
        return 0;
    }
    BiTree p=T,parent;//p用来查找树
    while (p)
    {
        parent=p;//parent用来查找p的父亲
        if(k>p->key){
            p=p->rchild;
        } else if(k<p->key){
            p=p->lchild;
        } else{
            return -1;//相等元素不可以放入查找树，考研不会考这类问题
        }
    }
    //接下来判断放在父亲左边还是右边
    if(k>parent->key){
        parent->rchild=TreeNew;
    } else{
        parent->lchild=TreeNew;
    }
    return 0;
}

void Creat_BST(BiTree &T,KeyType* str,int len)
{
    int i;
    for(i=0;i<len;i++){
        BST_Insert(T,str[i]);
    }
}

void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        printf("%3d",T->key);
        InOrder(T->rchild);
    }
}

BiTree Search_BST(BiTree T,int k,BiTree &p)
{
    p=NULL;
    while (T!=NULL&&k!=T->key){
        p=T;
        if(k>T->key){
            T=T->rchild;
        } else{
            T=T->lchild;
        }
    }
    return T;
}
//二叉排序树删除代码
void Delete_BST(BiTree& root,KeyType x)
{
    if(NULL==root){
        return;
    }
    if(root->key>x)//如果当前结点大于要删除的结点，往左子树找
    {
        Delete_BST(root->lchild,x);
    } else if(root->key<x)//如果当前结点小于要删除的结点，往右子树找
    {
        Delete_BST(root->rchild,x);
    } else//找到了要删除的结点
    {
        if(NULL==root->lchild)//左子树为空，右子树顶上去
        {
            BiTree temper=root;
            root=root->rchild;
            free(temper);
        } else if(NULL==root->rchild)//右 子树为空，左子树顶上去
        {
            BiTree temper=root;
            root=root->lchild;
            free(temper);
        } else//两边都不为空
        //一般的删除策略是左子树的最大数据 或者 右子树最小数据，代替要删除的结点（这里采用查找左子树最大数据来代替，最大数据是左子树的最右结点）
        {
            BiTree temper=root->lchild;
            while (temper->rchild!=NULL)
            {
                temper=temper->rchild;
            }
            root->key=temper->key;//把temper对应的位置放到要删除的位置
            Delete_BST(root->lchild,temper->key);//在左子树中找到temper的值，并把它删除
        }
    }
}
//二叉排序树新建，中序遍历，查找
int main() {
    BiTree T=NULL;
    int str[7]={54,20,66,40,28,79,58};
    Creat_BST(T,str,7);
    InOrder(T);//中序遍历二叉查找树是由小到大的
    printf("\n");
    BiTree search,p;
    search= Search_BST(T,54,p);
    if(search){
        printf("find the key %d\n",search->key);
    } else{
        printf("Not find");
    }
    Delete_BST(T,20);
    InOrder(T);
    printf("\n");
    return 0;
}
