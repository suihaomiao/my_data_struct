#include "sqQueue.h"

//队列初始化
void SqQueue_init(sqQueue *q)
{
    //队列初始状态front == rear ==0
    q->front = 0;
    q->rear = 0;
    q->max_size = 10;
    q->increment_size = 5;
    q->queue = (ElemType *)malloc(sizeof(ElemType) * q->max_size);
    if(q == NULL)
    {
        printf("队列创建失败！\n");
    }
}

//队列清空
void SqQueue_clear(sqQueue *q)
{
    memset(q->queue, 0, sizeof(ElemType) * q->max_size);
    q->max_size = 10;
    q->front = 0;
    q->rear = 0;
}

//队列长度
unsigned int SqQueue_length(sqQueue *q)
{
    if(q->rear == q->front) return 0;
    return q->rear - q->front;
}

//队列插入数据
//队列插入数据必须从队尾插入
int SqQueue_en(sqQueue *q, ElemType *e)
{
    if((q->rear >= q->max_size) && (q->rear != q->front))
    {
        //此时队伍满，需扩大队伍容量
        q->max_size += q->increment_size;
        q->queue = (ElemType *)realloc(q->queue, sizeof(ElemType) * q->max_size);
        if(q == NULL)
        {
            printf("分配内存失败！\n");
            return -1;
        }
    }

    memcpy(q->queue + q->rear, e, sizeof(ElemType));
    q->rear++;
    return 0;
}

//队列打印
void SqQueue_print(sqQueue *q)
{
    for(int i = q->front; i < q->rear; i++)
    {
        printf("第%d个元素为：%d\n",i+1,q->queue[i]);
    }
}

//队列是否为空
int SqQueue_empty(sqQueue *q)
{
    if((q->rear == q->front) && (q->front == 0))
        return 0;
    return 1;
}

//销毁队列
void SqQueue_destroy(sqQueue *q)
{
    free(q->queue);
}


//队列删除数据
int SqQueue_de(sqQueue *q, ElemType *e)
{
    if(q->front == q->rear)
    {
        if(q->front == 0)
        {
            printf("此队列初始化未加入数据，无法删除元素\n");
            return -1;
        }
        printf("此队列为空，无法删除元素\n");
        return -1;
    }
    memcpy(e, q->queue + q->front, sizeof(ElemType));
    memset(q->queue + q->front, 0, sizeof(ElemType));

    //删除元素后，不处理会形成假溢出的情况
    //即添加n个元素后，又删除n个元素，会出现rea == front；
    //此时插入时，会向后继续扩展空间，前面的内存空间就浪费了；
    //因此，在删除元素后，把元素依次向前移动一位；
    //即front永远指向0（那这样front的意义在哪？）
    //时间复杂度还是O(n)!!!!!!
    ElemType *temp = (ElemType *)malloc(sizeof(ElemType) * (q->rear - 1));
    memcpy(temp, q->queue + 1, sizeof(ElemType) * (q->rear - 1));
    memcpy(q->queue, temp, sizeof(ElemType) * (q->rear - 1));
    memset(q->queue + q->rear, 0, sizeof(ElemType));
    q->rear--;
    printf("q->rear = %d\n", q->rear);
    printf("q->front = %d\n", q->front);
    return 0;
}


