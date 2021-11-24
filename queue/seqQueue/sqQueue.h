#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int ElemType;

typedef struct SQQUEUE
{
    ElemType *queue;
    unsigned int front; //头
    unsigned int rear;  //尾
    unsigned int max_size;          //最大容量
    unsigned int increment_size;    //增长空间

}sqQueue, *sqQueuelist;

// 队列的插入称为进队，队列的删除称为出队
// 数据元素从**rear（队尾，上方）进队，从front（队首，下方）**出队
// 先进入队列的元素比后进入队列的元素先出队列（后进入队列的元素比先进入的元素后出队列），即队列是一个先进先出(FIFO)表
// 队列判空条件为：front == rear, 而front=rear=0是队列初始状态（本书约定）
// 进队时，先把元素插入到rear所指示的位置，然后rear++(保证rear始终指向队尾元素的后一位)
// 出队时，先取出front所指示的队首元素，然后front++(保证front始终指向真正的队首元素)
// 如果存储队列长度为maxsize，则rear >= maxsize时，队满；当rear == front时，队空

//队列初始化
void SqQueue_init(sqQueue *q);

//队列清空
void SqQueue_clear(sqQueue *q);

//队列长度
unsigned int SqQueue_length(sqQueue *q);

//队列插入数据
int SqQueue_en(sqQueue *q, ElemType *e);

//队列删除数据
int SqQueue_de(sqQueue *q, ElemType *e);

//队列打印
void SqQueue_print(sqQueue *q);

//队列是否为空
int SqQueue_empty(sqQueue *q);

//销毁队列
void SqQueue_destroy(sqQueue *q);






#endif