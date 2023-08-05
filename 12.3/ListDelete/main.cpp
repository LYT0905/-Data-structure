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
//往第i个位置删除元素
//删除时L不会变，所以不需要加引用
bool ListDelete(LinkList L,int i)
{
    LinkList p= GetElem(L,i-1);
    if(p == NULL)
    {
        return false;
    }
    LinkList q =p->next ;//拿到要删除的结点指针
    p->next = q->next;//断链
    free(q);//释放被删除结点的空间
    return true;
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
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    ListDelete(L,2);
    printf("\n");
    print_list(L);
    return 0;
}
