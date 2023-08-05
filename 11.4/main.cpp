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
//按位置查找
LinkList GetElem(LNode* L,int SearchPos)
{
    int i = 0;
    if(SearchPos<0){
        return NULL;
    }
    while (L!=NULL && i<SearchPos)
    {
        L = L->next;
        i++;
    }
    return L;
}
//按值查找
LNode *LocateElem(LinkList L,ElementType ElemValue)
{
    while(L!=NULL)
    {
        if(L->data == ElemValue){
            return L;
        }
        L= L->next;
    }
    return  NULL;
}
//往第i个位置插入元素
bool LinkListInsert(LNode *L,int i,int InsertValue)
{
    LinkList p = GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LinkList q;
    q = (LinkList)malloc(sizeof(LNode)); //为新结点申请空间
    q->data = InsertValue;
    q->next = p->next;
    p->next = q;
    return true;
}
int main() {
    LinkList L,search;//search用来存储拿到的某一个节点
    list_tail_insert(L);
    print_list(L);
    //按位置查找
    search = GetElem(L,4);
    if(search!=NULL){
        printf("\nsuccess find element\n");
        printf("%d",search->data);
    }else{
        printf("failed");
    }
    //按值查找
    search = LocateElem(L,2);
    if(search!=NULL){
        printf("\nsuccess find element\n");
        printf("%d\n",search->data);
    }else{
        printf("failed");
    }
    //往第i个位置插入元素
    LinkListInsert(L,1,888);
    print_list(L);
    return 0;
}
