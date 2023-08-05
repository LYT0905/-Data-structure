//顺序表插入、删除以及查找完整代码
#include <stdio.h>

#define Maxsize 50
typedef int ElemType; //让顺序表存储其他类型元素时，可以快速完成代码修改
//ElenType翻译过来是元素类型
typedef struct
{
    ElemType data[Maxsize];
    int length; //顺序表长度
}SqList;
//顺序表的插入，因为L会改变，所以用引用&，i是插入的位置
bool ListInsert(SqList &L,int i,ElemType element)
{
    //判断i是否合法
    if(i<1 || i>L.length+1){
        return false;
    }
    //判断是否已满，如果存储空间满了，不能插入
    if(L.length == Maxsize){
        return false;//未插入放回false
    }
    //把后面的元素以此往后移动，空出位置，来放要插入的元素
    for(int j = L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element;//放入要插入的元素
    L.length++;//顺序表长度加1
    return true;//插入成功放回true
}
//删除顺序表中的元素，i是删除的位置，e是为了获取被删除元素的值
bool ListDelete(SqList &L,int i,ElemType &e)
{
    //判断删除位置是否合法
    if(i<1 || i>L.length)
    {
        return false; //一旦走到return函数就结束了
    }
    e = L.data[i - 1]; //首先保存删除元素的值
    int j;
    for(j = i; j<L.length; j++) //往前移动元素
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
//查找某个元素位置，查到了就返回对应位置，没找到就返回0
int LocateElement(SqList L,ElemType element)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(element == L.data[i])
        {
            return i+1; //因为i是数组下标，+1才是顺序表下标
        }
    }
    return 0; //循环结束没找到
}
//打印顺序表
void PrintList(SqList L)
{
    int i;
    for(i=0;i<L.length;i++){
        printf("%3d",L.data[i]);//为了打印到同一行，所以不加换行符
    }
}
//顺序表的初始化及插入操作实战
int main()
{
    SqList L; //定义一个顺序表，变量L
    bool ret; //用来装函数放回值
    L.data[0] = 1; //放置元素
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3; //设置长度
    ret = ListInsert(L,3,60);
    if (ret)
    {
        printf("sqlist insert success\n");
        PrintList(L);
    }else
    {
        printf("sqlist insert failed\n");}
    printf("\n-----------------\n");
    ElemType del; //保存删除元素
    ret = ListDelete(L,2,del);
    if(ret)
    {
        printf("sqlist delete success\n");
        printf("delete element = %d\n",del);
        PrintList(L); //顺序表打印
    }
    else
    {
        printf("sqlist delete failed");
    }
    int pos; //存储元素位置
    pos = LocateElement(L,30);
    if(pos)
    {
        printf("\nfind this element\n");
        printf("element pos = %d\n",pos);
    }else{
        printf("\ndon't find this element\n");
    }
    return 0;
}
