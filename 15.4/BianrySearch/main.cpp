#include <stdio.h>
#include "stdlib.h"
#include "time.h"
typedef int ElemType;
typedef struct{
    ElemType *elem;//整形指针,申请的堆空间起始地址会存入elem里面
    ElemType TableLen;//存储动态数组里边元素的个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len;
    ST.elem=(ElemType*) malloc(sizeof (int)*ST.TableLen);
    //生成随机数代码，可以不要，考研不考
    int i;
    srand(time(NULL));
    for(i=0;i<ST.TableLen;i++)//因为是第零个哨兵，所以从1随机
    {
        ST.elem[i]=rand()%100;//为了随机生成的数都在0-99之间
    }
}

//打印顺序表
void ST_Print(SSTable ST){
    int i;
    for(i=0;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}
//实现二分查找
int BianrySearch(SSTable L,ElemType key)
{
    int low=0;
    int high=L.TableLen-1;
    int mid;
    while (low<=high)//low<=high,可以让mid既取到low，也取到high
    {
        mid=(low+high)/2;
        if(key>L.elem[mid])//如果目标大于中位数
        {
            low=mid+1;
        } else if(key<L.elem[mid])
        {
            high=mid-1;
        } else
        {
            return mid;
        }
    }
    return -1;
}
//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left指针和right指针是指向数组中的任意两个元素
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值；小于，返回负值；等于，返回0
int compare(const void *left,const void *right)
{
    return *(int *)left-*(int *)right;//从小到大
    //*(int *)right-*(int *)left;//从大到小排序
}
//折半查找（二分查找）
int main() {
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);
    qsort(ST.elem,ST.TableLen,sizeof (int),compare);//排序
    ST_Print(ST);
    ElemType key;
    printf("please input your key：\n");
    scanf("%d",&key);
    int pos=BianrySearch(ST,key);
    if(pos!=-1){
        printf("find the key %d\n",pos);
    } else{
        printf("failed\n");
    }
    return 0;
}
