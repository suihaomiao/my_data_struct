#include "queue.h"

int main()
{
    Queue q;
    Queue_init(&q, 8);
    if(!Queue_empty(&q))
        printf("此队列为空！\n");
    for(int i = 20; i >0; i--)
    {
        Queue_en(&q, &i);
    }
    int ee;
    Queue_de(&q, &ee);
    Queue_de(&q, &ee);
    Queue_de(&q, &ee);
    Queue_de(&q, &ee);
    Queue_de(&q, &ee);

    int e = 19920522;   Queue_en(&q, &e);
    e = 19920907;       Queue_en(&q, &e);

    Queue_print(&q);
    if(!Queue_empty(&q))
        printf("此队列为空！\n");
}

