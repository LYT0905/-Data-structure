#include "stdio.h"
#include "stdlib.h"


//考研初试只需要完成 setPartition 即可
int setPartition(int a[], int n) {
    int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
    int s1 = 0, s2 = 0;
    while (flag) //当low=k-1，也就是n/2-1时，分割结束
    {
        pivotkey = a[low]; //选择枢轴
        while (low < high) { //基于枢轴对数据进行划分
            while (low < high && a[high] >= pivotkey)
                --high;
            if (low != high)
                a[low] = a[high];
            while (low < high && a[low] <= pivotkey)
                ++low;
            if (low != high)
                a[high] = a[low];
        } //end of while(low<high)
        a[low] = pivotkey;
        if (low == k - 1)//如果枢轴是第 n/2 小元素，划分成功
        {
            flag = 0;
        } else//是否继续划分
        {
            if(low<k-1)
            {
                low0=++low;//low0 只是做暂存，为下次使用准备，这里我们++low 后，low 比分割值大 1
                high=high0;//把上次暂存的 high0
            } else
            {
                high0=--high;//high0 只是做暂存，为下次使用准备
                low=low0;//把上次暂存的 low0 拿
            }
        }
    }
    //如果 n 是偶数，就是各分一半，如果 n 是奇数，s2 比 s1 多一个元素
    for(i=0;i<k;i++)
    {
        s1+=a[i];
    }
    for(i=k;i<n;i++)
    {
        s2+=a[i];
    }
    return s2-s1;
}




int main() {
    int A[10] = { 4,1,12, 18, 7,13, 18, 16, 2, 15 };
    int difference;
    difference=setPartition(A, 10);//考研初试只需要完成 setPartition 即可，无需编写这个 main 函数
    printf("%d\n", difference);
    return 0;
}
