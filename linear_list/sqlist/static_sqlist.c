#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "static_sqlist.h"

//创建表
void Seqlist_creat(Seqlist &l, int max_size = MAXSIZE){
    l = (Seqlist *)malloc(max_size * sizeof(ElemType));
    if(l == NULL) printf("creat Seqlist erro!");
    //将全部元素初始化为0
    memset(l, 0, max_size * sizeof(ElemType));
}

//清空表
void Seqlist_clear(Seqlist &l)
{
    
}