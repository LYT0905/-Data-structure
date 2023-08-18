#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "string.h"

typedef int ElemType;
typedef struct
{
    ElemType *elem;//指向元素的起始地址
    int Tablen;//元素个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.Tablen=len;
    ST.elem= (ElemType *)malloc(sizeof (ElemType)*ST.Tablen);//申请一块堆空间，当数组使用
    int i;
    srand(time(NULL));//随机数生成，每执行一次代码随机生成10个数
    for(i=0;i<ST.Tablen;i++){
        ST.elem[i]=rand()%100;//随机生成0-99
    }
}

void Init_Print(SSTable ST)
{
    for (int i = 0; i < ST.Tablen; i++) {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void swap(int &a,int &b){
    int temper;
    temper=a;
    a=b;
    b=temper;
}

//往往都是用两层循环,优先写内层循环，再写外层循环
void BubbleSort(ElemType *A,int len)
{
    int i,j;
    bool flag;
    for(i=0;i<len-1;i++)//控制有序数的数目
    {
        flag= false;
        for(j=len-1;j>0;j--)//内层控制比较和交换
        {
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag= true;
            }
        }
        if(false==flag)//如果一趟没有发生任何交换，就说明是有序的
        {
            return;
        }
    }
}

//冒泡排序
int main() {
    SSTable ST;
    ST_Init(ST,10);
//    ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
    //内存copy接口，当你copy整型数组，或者浮点型，用memccpy,不能用strcpy,初试考memcpy概率很低
//    memcpy(ST.elem,sizeof (A));//这是为了降低调试难度，每次数组数据固定而设计的
    Init_Print(ST);
    BubbleSort(ST.elem,10);
    Init_Print(ST);
    return 0;
}
