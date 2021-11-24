#include "sqQueue.h"

int main()
{
    sqQueue q;
    SqQueue_init(&q);
    ElemType e = 0;
    SqQueue_de(&q, &e);
    printf("队列长度为:%d\n",SqQueue_length(&q));
    if(!SqQueue_empty(&q)) printf("此队列为空!\n");
    else{
        printf("此队列不为空！\n");
    }
    for(int i = 1; i <= 20; i++)
    {
        SqQueue_en(&q, &i);
    }
    SqQueue_print(&q);

    int j = 1;
    while(q.rear != q.front)
    {
        SqQueue_de(&q,&e);
        printf("删除队列第%d位元素：%d\n",j, e);
        ++j;
    }

    if(!SqQueue_empty(&q)) printf("此队列为空!\n");
    else{
        printf("此队列不为空！\n");
    }
    printf("队列长度为:%d\n",SqQueue_length(&q));

    SqQueue_destroy(&q);
}
