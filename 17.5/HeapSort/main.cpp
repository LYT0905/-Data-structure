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
    for (int i = 0; i < ST.Tablen; i++)
    {
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

void swap(int &a,int &b)
{
    int temper;
    temper=a;
    a=b;
    b=temper;
}

//把某个子树调整为大根堆
void AdjustDown(ElemType A[],int k,int len)
{
    int dad=k;//父亲的下标
    int son=2*dad+1;//左孩子的下标
    while (son<len)
    {
        if(son+1<len&&A[son]<A[son+1])
        {
            son++;//拿右孩子
        }
        if(A[son]>A[dad])//如果孩子大于父亲
        {
            swap(A[son],A[dad]);//交换
            dad=son;//son重新作为dad，去判断下面的子树是否满足大根堆
            son=2*dad+1;
        } else
        {
            break;
        }
    }
}

void HeapSort1(ElemType A[],int len)
{
    int i;
    //就是把堆调整为大根堆
    for(i=len/2-1;i>=0;i--)
    {
        AdjustDown(A,i,len);
    }
    swap(A[0],A[len-1]);//交换根部元素和最后一个元素
    //下面的策略是，不断调整剩余元素为大根堆，因为根部最大，所以再次与 A[i]交换（相当于放
//    到数组后面），循环往复
    for(i=len-1;i>1;i--)
    {
        AdjustDown(A,0,i);;//剩下元素调整为大根堆
        swap(A[0],A[i-1]);//交换根部元素和无序数组的最后一个元素
    }
}


int main() {
    SSTable ST;
    ST_Init(ST,10);//初始化
    ElemType A[10] = { 3, 87, 2, 93, 78, 56, 61, 38, 12, 40 };
    memcpy(ST.elem,A,sizeof(A));
    Init_Print(ST);
//HeapSort(ST.elem, 9);//王道书零号元素不参与排序，考研考的都是零号元素要参与排序
    HeapSort1(ST.elem,10);//所有元素参与排序
    Init_Print(ST);
    return 0;
}
