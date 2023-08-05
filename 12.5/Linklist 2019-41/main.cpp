#include <stdio.h>
#include <stdlib.h>
//尾插法插入链表
typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
}LNode,*LinkList;
void list_tail_insert(LNode* &L)
{
    L= (LinkList)malloc(sizeof(LNode)); //申请头结点空间，让头指针指向头结点
    L->next = NULL;
    ElementType  x;
    scanf("%d",&x);
    LNode *s,*r=L; //s是用来指向原来申请的新结点，r始终指向链表尾部
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode)); //为新结点申请内存空间
        s->data = x;
        r->next = s; //新结点给尾结点的next指针
        r = s; //r要指向新的尾部
        scanf("%d",&x);
    }
    r->next = NULL; //让尾结点的next为NULL
}
void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d",L->data);
        L = L->next;
    }
}
//找链表中间结点，并设置L2结点
void find_middle(LinkList L,LinkList &L2)
{
    L2=(LinkList) malloc(sizeof(LNode));//第二条链表的头结点
    LinkList ppre,pcur;//双指针遍历，考研初试常考
    ppre = pcur = L->next;
    while (pcur)
    {
        pcur = pcur->next;
        if(pcur==NULL)//防止pcur为NULL
        {
            break;
        }
        pcur = pcur->next;
        if(pcur==NULL)//w为了使偶数个，ppre依然a1、a2到a6中的a3结点
        {
            break;
        }
        ppre = ppre->next;
    }
    L2->next = ppre->next;//由L2头结点指向后面一半链表
    ppre->next = NULL;//前一半最后一个结点，next要为NULL
}
//逆转链表
void reverse(LinkList L2){
    LinkList r,s,t;
    r = L2->next;
    if(r==NULL)
    {
        return;//链表为空
    }
    s = r->next;
    if(s==NULL)
    {
        return;//链表只有一个结点
    }
    t = s->next;
    while (t)
    {
        s->next = r;//原地逆置
        r = s;//以下三句是三个指针同时走一步
        s = t;
        t = t->next;
    }
    s->next = r;
    L2->next->next = NULL;//逆置后，链表的第一个结点要为NULL
    L2->next = s;//s是第一个结点，L2指向它
}
//合并两个链表
void merge(LinkList L,LinkList L2)
{
    LinkList pcur,p,q;
    pcur = L->next;//pcur始终指向组合链表的链表尾
    p = pcur->next;//p用来遍历L链表
    q = L2->next;//q指向L2第一个结点,q用来遍历L2链表
    while (p!=NULL&&q!=NULL)
    {
        pcur->next=q;
        q = q->next;//指向下一个
        pcur = pcur->next;
        pcur->next = p;
        p = p->next;//指向下一个
        pcur = pcur->next;
    }
    //任何一个链表都有可能剩余一个结点，放进来即可
    if(p!=NULL){
        pcur->next=p;
    }
    if(q!=NULL){
        pcur->next=q;
    }
}
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    //寻找中间结点，并返回第二条链表
    LinkList L2 = NULL;
    find_middle(L,L2);//只有一个结点时，L2是没有结点的
    printf("\n----------------\n");
    print_list(L);
    printf("\n----------------\n");
    print_list(L2);
    printf("\n----------------\n");
    reverse(L2);
    print_list(L2);
    printf("\n----------------\n");
    merge(L,L2);
    free(L2);
    print_list(L);
    return 0;
}
