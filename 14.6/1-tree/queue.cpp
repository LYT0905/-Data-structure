//
// Created by 27132 on 2023/8/1.
//
#include "function.h"
//队列初始化，使用带头结点的链表实现
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear= (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
     if(Q.rear==Q.front){
         return true;
     } else{
         return false;
     }
}
//入队
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;//要让next为NULL
    Q.rear->next=s;//尾指针都next指向s，因为从尾部入队
    Q.rear=s;//rear要指向新的尾部

}
//出队
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)
    {
        return false;
    }
    LinkNode *q=Q.front->next;//拿到第一个结点，指向q
    x=q->data;//获取要出队的元素值
    Q.front->next=q->next;//让一个结点断链
    if(Q.rear==q)//链表只剩一个结点时，被删除后，要改变rear
    {
        Q.front=Q.rear;
    }
    free(q);
    return true;
}