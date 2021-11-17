#include "linklist.h"


int main(){
    //C语言不能直接用const 代替常量
    //C语言的const只能表示read-only;不能表示constant
    //C++就可以。
    //另外 int a[n]，想要初始化需要用memset，不能用列表初始化
    const int n = 10;
    ElemType a[10] = {10,9,8,7,6,5,4,3,2,1};
    ElemType b[10] = {100,200,300,400,500,600,700,800,900,1000};
    //printf("%ld\n", sizeof(LNode));
    PLNode l = Linklist_init();
    if(l == NULL) printf("l == NULL");
    else
    {
        printf("l的地址为：%p\n",l);
    }

    for(int i = 0; i < 20; i++)
    {
        Linklist_push_back(l, &i);
    }

    Linklist_L_Rear(l, b, 10);
    Linklist_L_Head(l, a, 10);

    int e = 19920522;
    int ee = 19920918;
    if(!Linklist_insert_my(l, 14,&e))
        printf("插入元素失败！");
    
    if(!Linklist_push(l, 23, &ee))
        printf("插入元素失败！");
    printf("链表l的长度为：%d\n",Linklist_length(l));

    
    if(Linklist_location(l, &ee))
    {
        printf("在链表l中找到%d元素，位于链表第%d位\n", e, Linklist_locate_pos(l, &ee));
    }
    else{
        printf("无法在链表l中找到%d元素\n",ee);
    }

    Linklist_delete_ElemType(l, &e);

    Linklist_print(l);

}