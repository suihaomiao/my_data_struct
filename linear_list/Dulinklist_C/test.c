#include "dulinklist_C.h"


int main()
{
    DuLinkNode *l = Dulinklist_init();
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    Dulinklist_Rear(l, a, 10);
    Dulinklist_print(l);
    printf("链表长度 = %d\n",Dulinklist_length(l));
    //Dulinklist_destroy(l);
}