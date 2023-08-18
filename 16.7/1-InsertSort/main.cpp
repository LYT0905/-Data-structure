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

void InsertSort(ElemType *A,int n){
    int i,j,InsertVal;
    for(int i=1;i<n;i++)
    {
        InsertVal=A[i];//保存要插入的数
        for(j=i-1;j>=0&&A[j]>InsertVal;j--)//内层控制比较，j要大于等于0，同时arry[j]大于insertval时，arry[j]位置元素往后覆盖
        {
            A[j+1]=A[j];
        }
        A[j+1]=InsertVal;//把要插入的元素放到对应的位置
    }
}

int main() {
    SSTable ST;
    ST_Init(ST,10);
    Init_Print(ST);
    InsertSort(ST.elem,10);
    Init_Print(ST);
    return 0;
}
