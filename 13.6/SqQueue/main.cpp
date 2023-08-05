#include "stdio.h"
#include "stdlib.h"

#define MaxSize 5
//循环队列代码实战
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];//数组存储MaxSize-1个元素
    int front,rear;//定义队列头，队列尾
}SqQueue;

void InitQuqueue(SqQueue &Q)
{
    Q.front=Q.rear=0;//初始化循环队列,就是让头和尾部都指向零号
}
//判断队列是否为空
bool IsEmpty(SqQueue Q){
    return Q.rear==Q.front;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)//判断循环队列是否满了，满了就不能入队
    {
        return false;
    }
    Q.data[Q.rear]=x;//放入元素
    Q.rear=(Q.rear+1)%MaxSize;//rear要加1，如果大于数组最大下标，则要回到开头
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)//队列为空，无法出队
    {
        return false;
    }
    x=Q.data[Q.front];//出队
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main() {
    SqQueue Q;
    InitQuqueue(Q);
    bool ret;
    ret=IsEmpty(Q);
    if(ret){
        printf("SqQueue is Empty\n");
    } else{
        printf("SqQueue is not Empty\n");
    }
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    ret= EnQueue(Q,6);
    ret= EnQueue(Q,7);
    if(ret){
        printf("EnQueue sucessful\n");
    } else{
        printf("EnQueue failed\n");
    }
    ElemType element;
    ret = DeQueue(Q,element);
    if(ret){
        printf("DeQueue sucessful\n");
    } else{
        printf("DeQueue failed\n");
    }
    ret= EnQueue(Q,8);
    if(ret){
        printf("EnQueue sucessful\n");
    } else{
        printf("EnQueue failed\n");
    }
    return 0;
}
