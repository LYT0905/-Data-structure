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
    //多申请了个位置，用来存哨兵，不申请也没事
    ST.TableLen=len+1;
    ST.elem=(ElemType*) malloc(sizeof (int)*ST.TableLen);
    //生成随机数代码，可以不要，考研不考
    int i;
    srand(time(NULL));
    for(i=1;i<ST.TableLen;i++)//因为是第零个哨兵，所以从1随机
    {
        ST.elem[i]=rand()%100;//为了随机生成的数都在0-99之间
    }
}

//打印顺序表
void ST_Print(SSTable ST){
    int i;
    for(i=1;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}
//查找
int Search_Sq(SSTable ST,int key)
{
    ST.elem[0]=key;//key存在零号位置，作为哨兵,有了这个，可以少写一个i>=0的判断
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;i--);//从后面往前面找，如果找到了，i刚好就是对应位置
    return i;
}
//顺序查找
int main() {
    SSTable ST;
    ST_Init(ST,10);
    ST_Print(ST);//打印顺序表中元素
    ElemType key;
    printf("please input your search:\n");
    scanf("%d",&key);
    int pos;
    pos= Search_Sq(ST,key);
    if(pos){
        printf("find key,pos=%d\n",pos);
    } else{
        printf("Not find");
    }
    return 0;
}
