#include "dulinklist_C.h"

//初始化一个双向链表
DuLinkNode *Dulinklist_init()
{
    DuLinkNode *l = (DuLinkNode*)malloc(sizeof(DuLinkNode));
    if(l == NULL)
    {
        printf("初始化失败！\n");
        return NULL;
    }

    l->next = l;
    l->prev = l;
    return l;
}

//返回双向链表的长度
int Dulinklist_length(DuLinkNode *l)
{
    DuLinkNode *temp = l->next;
    if(temp == l) return 1;
    int index = 1;
    while(temp != l)
    {
        index++;
        temp = temp->next;
    }
    return index;
}

//双向链表尾插元素
void Dulinklist_Rear(DuLinkNode *l, ElemType a[], unsigned int  n)
{
    //双向链表，第一个节点的上一个节点认为是尾部
    DuLinkNode *temp = l->prev;
    DuLinkNode *node;
    for(int i = 0; i < n; i++)
    {
        node = (DuLinkNode *)malloc(sizeof(DuLinkNode));
        if(node == NULL)
        {
            printf("尾插节点分配内存失败！\n");
        }
        memcpy(&node->data, a+i, sizeof(DuLinkNode));
        //双向链表插入节点，分四步
        node->next = l;
        node->prev = temp;
        l->prev = node;
        temp->next = node;
        //此时node才是最后一个节点
        temp = node;
    }

    return;
}


//打印链表
void Dulinklist_print(DuLinkNode *l)
{
    DuLinkNode *temp = l->next;
    int index = 1;
    while(temp != l)
    {
        printf("第%d个元素为%d，地址为%p\n",index, temp->data,&temp);
        index++;
        temp = temp->next;
    }

}


//销毁链表
void Dulinklist_destroy(DuLinkNode *l)
{
    DuLinkNode *temp = l->next;
    DuLinkNode *destroy = temp;
    int index = 1;
    while (temp != l)
    {
        index++;
        printf("index = %d\n",index);
        free(destroy);
        destroy = temp->next;
        temp = temp->next;
    }
    free(l);
    l = NULL;
}
