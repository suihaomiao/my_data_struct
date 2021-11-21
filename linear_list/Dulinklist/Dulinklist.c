#include "Dulinklist.h"

//初始化双向链表
DuNodeList Dulinklist_init()
{
    DuNodeList l = (DuNodeList)malloc(sizeof(DuNode));
    if(l == NULL)
    {
        printf("初始化双向链表失败！\n");
    }
    l->next = NULL;
    l->prev = NULL;
    return l;
}

//双向链表的长度
int Dulinklist_length(DuNodeList l)
{
    DuNodeList temp = l->next;
    if(temp == NULL) return 0;
    int index = 1;
    while(temp->next)
    {
        index++;
        temp = temp->next;
    }
    return index;
}

//双向链表定位
int Dulinklist_location(DuNodeList l, Elemtype e)
{
    DuNodeList temp = l->next;
    if(Dulinklist_length(l) <= 0) 
    {
        printf("双向链表长度为0！\n");
        return -1;
    }
    int index = 1;
    while (temp->next)
    {
        if(!memcmp(&temp->data, &e, sizeof(Elemtype)))
        {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

//插入元素操作，在i后面插入元素
bool Dulinklist_insert(DuNodeList l, int i, Elemtype e)
{
    if(Dulinklist_length(l) < i)
    {
        printf("insert元素失败，length = %d, 插入位置i = %d\n",Dulinklist_length(l), i);
        return false;
    }
    DuNodeList node = (DuNodeList)malloc(sizeof(DuNode));
    if(node == NULL) return false;
    memcpy(&node->data, &e, sizeof(Elemtype));

    DuNodeList temp = l->next;
    int index = 1;
    while(temp->next)
    {
        if(index == i)
        {
            //printf("index == %d\n",index);
            //temp表示第i位的节点，node表示即将添加的节点
            //双向链表插入元素需要四步，插入的元素的prev和next需要指向各自的元素
            //原本的prev和next节点也需要分别指向插入的元素节点node
            //此步表示node的下一个节点是原来节点的下一个节点
            node->next = temp->next;
            //node的上一个节点是temp
            node->prev = temp;
            //此步表示temp的下一个节点的prev指向node
            node->next->prev = node;
            //原本的temp节点的next指向node
            temp->next = node;
            //Dulinklist_print(l);
            
            return true;
        }
        temp = temp->next;
        index++;
    }
    return false;
}

//双向链表尾部添加元素，返回值为此时链表的长度
int Dulinklist_push_back(DuNodeList l, Elemtype e)
{
    int index = 0;
    DuNodeList node = (DuNodeList)malloc(sizeof(Elemtype));
    if(node == NULL) return -1;
    DuNodeList temp = l;
    while(temp->next)
    {
        index++;
        temp = temp->next;
    }
    //此时temp指向最后一个节点
    memcpy(&node->data, &e, sizeof(Elemtype));
    temp->next = node;
    node->next = NULL;
    node->prev = temp;
    index++;
    return index;
}

//打印链表
void Dulinklist_print(DuNodeList l){
    if(l->next == NULL) return;

    DuNodeList node = l->next;
    int index = 1;
    while(node)
    {
        printf("链表l中第%d位元素为%d\n",index, node->data);
        index++;
        node = node->next;
    }
}

//双向链表头部添加元素
int Dulinklist_pop_front(DuNodeList l, Elemtype e)
{
    DuNodeList node = (DuNodeList)malloc(sizeof(DuNode));
    memcpy(&node->data, &e, sizeof(Elemtype));
    //插入元素，分四步
    //node节点的上下需要赋值
    node->next = l->next;
    node->prev = l;
    //原本的位置需要赋值；
    l->next = node;
    if(Dulinklist_length(l) < 1) 
    {
        node->next = NULL;
        return 0;
    }
    node->next->prev = node;
    return 0;
}

//删除元素
bool Dulinklist_delete_item(DuNodeList l, Elemtype e)
{
    DuNodeList node,temp;
    temp = l->next;
    while(temp)
    {
        if(!memcmp(&temp->data, &e, sizeof(Elemtype)))
        {
            //删除该元素
            //双向链表删除元素，需要两步操作
            //1、该节点的上一个节的next指向该节点的下一个节点
            //2、该节点的下一个节点的prev指向该节点的上一个节点
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
            return true;
        }
        temp = temp->next;
    }
    printf("无法在链表中找到%d节点\n",e);
    return false;
}


//尾插元素
void Dulinklist_insert_Rear(DuNodeList l, Elemtype a[], int n)
{
    DuNodeList node = l->next;
    DuNodeList temp;
    while(node->next)
    {
        node = node->next;
    }
    for(int i = 0; i < n; i++)
    {
        temp = (DuNodeList)malloc(sizeof(DuNode));
        memcpy(&temp->data, a+i, sizeof(Elemtype));
        temp->prev = node;
        temp->next = NULL;
        node->next = temp;
        node = node->next;
    }

}

//前插元素
void Dulinklist_insert_Head(DuNodeList l, Elemtype a[], int n)
{
    DuNodeList node,temp;
    temp = l->next;
    for(int i = 0; i < n; i++)
    {
        node =(DuNodeList)malloc(sizeof(DuNode));
        memcpy(&node->data,a+i, sizeof(Elemtype));
        node->next = temp;
        node->prev = l;
        l->next = node;
        if(temp != NULL){
            temp->prev = node;
        }
        temp = l->next;
    }
}

