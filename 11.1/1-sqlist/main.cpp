#include <stdio.h>
//课时10作业


#define Maxsize 50
typedef int ElemType; //让顺序表存储其他类型元素时，可以快速完成代码修改
//ElenType翻译过来是元素类型
typedef struct
{
    ElemType data[Maxsize];
    int length; //顺序表长度
}SqList;

void ListInsert(SqList &L,int pos,ElemType InsertValue)
{
    //判断位置是否合法
    if(pos<1 || pos>L.length+1)
    {
        return;
    }
    if(pos>L.length){
        return;
    }
    int j;
    for(j=L.length;j>=pos;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[pos-1] = InsertValue;
    L.length++;
}
//打印顺序表
void PrintList(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%3d",L.data[i]);
    }
}
//删除值
bool ListDelete(SqList &L,int pos)
{
    //判断1删除位置是否合法
    if(pos<1 || pos>L.length)
    {
        return  false;
    }
    //往前移动元素
    int j;
    for(j=pos;j<L.length;j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
int main()
{
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ElemType InsertValue;
    //读入输入元素
    scanf("%d",&InsertValue);
    ListInsert(L,2,InsertValue);
    PrintList(L);
    ElemType DeletePos;
    //读取删除位置
    scanf("%d",&DeletePos);
    bool ret;
    ret = ListDelete(L,DeletePos);
    if(ret)
    {
        PrintList(L);
    }else
    {
        printf("false\n");
    }
    return 0;
}