#include "Dulinklist.h"




int main()
{
    DuNodeList l = Dulinklist_init();
    for(int i = 1; i <= 20; i++)
    {
        printf("向链表添加元素%d，此时链表长度为%d\n",i,Dulinklist_push_back(l, i));
    }

    //printf("l的地址为:%p\n",l);

    Dulinklist_insert(l, 10, 19920522);
    Dulinklist_pop_front(l, 19920907);
    int e,index;
    e = 19920907;
    index = Dulinklist_location(l, e);
    if(index > 0)
    {
        printf("在链表中，可以找到%d元素，在第%d位\n",e,index);
    }
    else
    {
        printf("无法在链表中找到元素%d\n",e);
    }
    Dulinklist_print(l);
    int ee = 19920522;
    if(Dulinklist_delete_item(l, ee))
    {
        printf("成功删除%d元素\n",ee);
    }

    Elemtype a[] = {100,200,300,400,500,600,700,800,900,1000};
    Dulinklist_insert_Rear(l, a, 10);
    Elemtype b[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    Dulinklist_insert_Head(l, b, 10 );
    Dulinklist_print(l);

}