#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef int ElemType;
//49,38,65,97,76,13,27


void Merge(ElemType A[],int low,int mid,int high)
{
    static ElemType B[N];//加 static 的目的是无论递归调用多少次，都只有一个 B[N]
    int i,j,k;
    for(i=low;i<=high;i++)//复制元素到 B 中
    {
        B[i]=A[i];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)//合并两个有序数组
    {
        if (B[i] < B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j++;
        }
    }
    while (i<=mid)//如果有剩余元素，接着放入即可
    {
            A[k]=B[i];//前一半的有剩余的放入
            i++;
            k++;
    }
    while (j<=high)
    {
            A[k]=B[j];//后一半的有剩余的放入
            j++;
            k++;
    }
}

//归并排序不限制是两两归并，还是多个归并，考研都是考两两归并
void MergeSort(ElemType A[],int low,int high)//递归分割
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid);//排序好前一半
        MergeSort(A,mid+1,high);//排序好后一半
        Merge(A,low,mid,high);//讲两个排序好的数组合并
    }
}


void print(int* a)
{
    for(int i=0;i<N;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n");
}



int main() {
    int A[N]={49,38,65,97,76,13,27};//数组，7 个元素
    MergeSort(A,0,6);
    print(A);
    return 0;
}
