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
//快排的核心
//挖坑法
int Partition(ElemType  *A,int low,int high)
{
    ElemType pivot=A[low];//拿最左边的值作为分割值
    while (low<high){
        while (low<high&&A[high]>=pivot)
            high--;
        A[low]=A[high];//把比分割值小的那个元素，放到A[low]
        while (low<high&&A[low]<=pivot)
            low++;
        A[high]=A[low];//把比分割值大的那个元素，放到A[high]，因为刚才high的位置已经放到low的位置了
    }
    A[low]=pivot;//把分隔符放到中间位置，因为刚好左边都比它小，右边都比它大
    return low;//返回分割值所在下标
}


void Quick_Sort(ElemType  *A,int low,int high){
    if(low<high){
        int pivot_pos= Partition(A,low,high);//pivot用来存分割值位置
        Quick_Sort(A,low,pivot_pos-1);//前一半继续递归排好
        Quick_Sort(A,pivot_pos+1,high);
    }
}

int main() {
    SSTable ST;
    ST_Init(ST,10);
    ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
    //内存copy接口，当你copy整型数组，或者浮点型，用memccpy,不能用strcpy,初试考memcpy概率很低
    memcpy(ST.elem,A,sizeof (A)); //这是为了降低调试难度，每次数组数据固定而设计的
    Init_Print(ST);
    Quick_Sort(ST.elem,0,9);
    Init_Print(ST);
    return 0;
}
