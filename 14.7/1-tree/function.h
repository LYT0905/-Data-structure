//
// Created by 27132 on 2023/8/1.
//

#ifndef INC_1_TREE_FUNCTION_H
#define INC_1_TREE_FUNCTION_H
#include "stdio.h"
#include "stdlib.h"

typedef int BiElemType;
typedef struct BiTNode{
    BiElemType weight;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;


//tag结构体是辅助队列使用的
typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;
}tag_t,*ptag_t;
#endif //INC_1_TREE_FUNCTION_H
