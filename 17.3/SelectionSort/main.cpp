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

void SelectionSort(ElemType *A,int n)
{
    int i,j,min;//min记录最小元素下标
    for(i=0;i<n-1;i++)
    {
        min=i;//我们认为i号元素最小
        for(j=i;j<n;j++)//找到从i开始到最后的序列的最小值的下标
        {
            if(A[min]>A[j])//当某个元素A[j]小于了最小元素
            {
                min=j;//将下标j赋给min，min就记录下来了最小值的下标
            }
        }
        if(min!=j)
        {
            //遍历完成找到最小值的位置后，与A[i]交换，这样最小值就在前面
            swap(A[i],A[min]);
        }
    }
}


int main() {
    SSTable ST;
    ST_Init(ST,10);
    //    ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
    //内存copy接口，当你copy整型数组，或者浮点型，用memccpy,不能用strcpy,初试考memcpy概率很低
//    memcpy(ST.elem,sizeof (A));//这是为了降低调试难度，每次数组数据固定而设计的
    Init_Print(ST);
    SelectionSort(ST.elem,10);
    Init_Print(ST);
    return 0;
}
