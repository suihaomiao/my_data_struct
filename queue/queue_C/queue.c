#include "queue.h"


//初始化队列
void Queue_init(Queue *q, unsigned int size)
{
    q->max_size = size;
    q->front = 0;
    q->rear = 0;
    q->increment_size = 3;
    q->queue = (ElemType *)malloc(sizeof(ElemType) * size);
    if(q->queue == NULL) printf("队列初始化失败！\n");
}


//队列长度
unsigned int Queue_length(Queue *q)
{
    //因为是循环链表，可能会出现rear - front < 0的情况，加上一个max_size保证返回的是正数
    return (q->rear - q->front + q->max_size) % q->max_size;
}

//清空队列
void Queue_clear(Queue *q)
{
    //数据清零
    memset(q->queue, 0, sizeof(ElemType) * q->max_size);
    q->front = 0;
    q->rear = 0;
}

//队列插入元素
int Queue_en(Queue *q, ElemType *e)
{
    //插入元素需要分以下几种情况
    //队列满，需扩大容量
    //队列不满，可以插入
    //插入时，若rear != q->max_size - 1;直接插入
    //反之，则认为rear已经到顶部，此时应该向底部空间插入，即向0插入

    //判断队列已满
    //这里判断满的条件为，rear == fornt && rear位置有元素
    //有元素只是简单的判断了 == 0；实际上是不严谨的
    if(((q->front == 0) && (q->rear == q->max_size - 1))||((q->front != 0) && (q->rear == q->front - 1)))
    {
        //扩大队列容量
        if(q->front == 0)
        {
            q->max_size += q->increment_size;
            q->queue = (ElemType *)realloc(q->queue ,sizeof(ElemType) * q->max_size);
            if(q->queue == NULL)
            {
                printf("重新分配内存失败！\n");
                return -1;
            }
        }
        else
        {
            ElemType *temp = (ElemType *)malloc(sizeof(ElemType) * q->max_size);
            memcpy(temp, q->queue, sizeof(ElemType) * q->max_size);
            q->queue = (ElemType *)realloc(q->queue, sizeof(ElemType) *(q->max_size + q->increment_size));
            if(q->queue == NULL)
            {
                printf("重新分配内存失败！\n");
                return -1;
            }
            memcpy(q->queue, temp + q->front, sizeof(ElemType) * (q->max_size - q->front));
            memcpy(q->queue + (q->max_size - q->front), temp, sizeof(ElemType) * q->front);
            free(temp);
            q->max_size += q->increment_size;
        }

    }

    //插入元素
     if((q->rear == (q->max_size - 1)) && (q->front != 0))
     {
         //认为底部空间见底，插入到第一位置
         memcpy(q->queue, e, sizeof(ElemType));
         q->rear = 0;
     }
     else
     {
         //底部空间未见底，可以直接插入
        memcpy(q->queue + q->rear, e, sizeof(ElemType));
        q->rear++;
     }
     return 0;
}

//队列删除元素
int Queue_de(Queue *q, ElemType *e)
{
    //删除元素分两种情况
    //1、front!= max_size - 1，可以直接删除
    //2、front== max_size - 1,删除后，需将front = 0;（如果front指向尾位置，删除后，需将front指向首位置）
    if(q->front != (q->max_size - 1))
    {
        memset(q->queue + q->front, 0, sizeof(ElemType));
        q->front++;
    }
    else
    {
        memset(q->queue + q->front, 0, sizeof(ElemType));
        q->front = 0;
    }
}

//打印队列
void Queue_print(Queue *q)
{
    //打印时，区分front < rear和front > rear的情况
    if(q->front <= q->rear)
    {
        //此时认为，rear没有向前插入元素
        for(int i = q->front; i < q->rear; i++)
        {
            printf("队列元素：%d\n", q->queue[i]);
        }
    }
    else
    {
        //此时认为，rear已经在前面插入
        for(int j = q->front; j < q->max_size-1; j++)
        {   
            //printf("队列元素：%d\n",*q->queue);
            printf("队列元素：%d\n",q->queue[j]);
        }
        for(int j = 0; j <= q->rear; j++)
        {
            printf("队列元素：%d\n",q->queue[j]);
        }
    }
}

//销毁队列
void Queue_destroy(Queue *q)
{
    free(q->queue);
}

//队列判断空
int Queue_empty(Queue *q)
{
    if(Queue_length(q) == 0)
        return 0;
    return 1;
}