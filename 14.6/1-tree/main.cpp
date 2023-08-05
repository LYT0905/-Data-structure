#include "function.h"

//前序遍历,也叫先序遍历，也是深度优先遍历
void PreOrder(BiTree p)
{
    if(p!=NULL)
    {
        printf("%c",p->c);
        PreOrder(p->lchild);//打印左子树
        PreOrder(p->rchild);//打印右子树
    }
}
//中序遍历
void InOrder(BiTree p)
{
    if(p!=NULL)
    {
        InOrder(p->lchild);//打印左子树
        printf("%c",p->c);
        InOrder(p->rchild);//打印右子树
    }
}
//后序遍历
void PostOrder(BiTree p)
{
    if(p!=NULL)
    {
        PostOrder(p->lchild);//打印左子树
        PostOrder(p->rchild);//打印右子树
        printf("%c",p->c);
    }
}

//层序遍历 层次遍历 也叫广度优先遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;//存储出队结点
    EnQueue(Q,T);//把根入队
    while (!IsEmpty(Q)){
        DeQueue(Q,p);
        putchar(p->c);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL)
        {
            EnQueue(Q,p->rchild);
        }
    }
}
int main() {
    BiTree pnew;//用来指向新申请的结点
    BiTree tree=NULL;//tree是指向树根的代表树
    char c;
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
    //abcdefghij
    while (scanf("%c",&c)) {
        if (c == '\n') {
            break;//读取到换行就结束
        }

        //calloc申请的空间大小是两个参数直接相乘，并对空间初始化，赋值为0
        pnew = (BiTree) calloc(1, sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptag_t) calloc(1, sizeof(tag_t));//给队列结点申请空间
        listpnew->p = pnew;
        //如果是树的第一个结点
        if (NULL == tree) {
            tree = pnew;//tree指向树的根结点
            phead = listpnew;//第一个结点，既是队列头，也是队列尾
            ptail = listpnew;
            pcur = listpnew;//pcur要指向要进入树的父亲元素
        } else {
            //让元素先入队列
            ptail->pnext = listpnew;
            ptail = listpnew;
            //接下来把b放入树中
            if (NULL == pcur->p->lchild) {
                pcur->p->lchild = pnew;//pcur左孩子为空就放左孩子
            } else if (NULL == pcur->p->rchild) {
                pcur->p->rchild = pnew;//pcur右孩子为空就放右孩子
                pcur = pcur->pnext;//当前左右孩子都有，pcur指向下一个
            }
        }
    }
    printf("-----PreOrder-----\n");//也叫先序遍历，先打印当前结点，再打印左孩子，然后右孩子
    PreOrder(tree);
    printf("\n-----InOrder-----\n");//先打印左孩子，再打印父亲，最后打印右孩子
    InOrder(tree);
    printf("\n-----PostOrder-----\n");//先打印左孩子，再打印右孩子，最后打印父亲
    PostOrder(tree);
    printf("\n----- LevelOrder-----\n");
    LevelOrder(tree);
    return 0;
}
