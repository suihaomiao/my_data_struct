#include "linklist.h"

//初始化一个元素列表
LNode *Linklist_init()
{
    LNode *l = (LNode *)malloc(sizeof(LNode));
    if(l == NULL) 
    {
        printf("创建链表失败！");
    }
    
    l->next = NULL;
    return l;
}


//尾插模式,在尾部插入数组
void Linklist_L_Rear(LNode *l, ElemType a[], int n)
{

    //end始终指向尾部节点
    LNode *end;
    LNode *now;
    //找到最后一个节点，在最后一个节点后面插入数据
    end = l;
    while(end->next)
    {
        end = end->next;
    }
    //开始插入数据
    for(int i = 0; i < n; i++)
    {
        //为now分配内存
        now = (LNode *)malloc(sizeof(LNode));
        //now赋值
        now->data = a[i];
        //end的下一个节点赋值给now，此时now已经加入到链表中
        end->next = now;
        //end始终指向下个节点
        end = now;
    }
    end->next = NULL;
}

//创建单链表，头插模式
void Linklist_L_Head(LNode *l, ElemType a[], int n)
{
    //LNode *start;   //始终指向第一个节点
    LNode *now;

    //l = (LNode *)malloc(sizeof(LNode));
    //l->next = NULL;
    for(int i = n-1; i >= 0; i--)
    {
        now = (LNode *)malloc(sizeof(LNode));
        now->data = a[i];
        //在头节点和第一个节点之间插入；
        now->next = l->next;
        //now是第一个节点，头节点始终指向第一个节点。
        l->next = now;
        //printf("添加一个节点，数据为：%d\n",now->data);
    }

}

//返回单链表的长度
int Linklist_length(LNode *l)
{
    int length = 0;
    LNode *now = l;
    while(now->next)
    {
        length++;
        now = now->next;
    }
    return length;
}

//遍历打印单链表
void Linklist_print(const LNode *l)
{
    int index = 1;
    LNode *now = l->next;
    while(now != NULL)
    {
        printf("表l中第%d个数据：%d\n",index, now->data);
        now = now->next;
        index++;
    }
}

//单链表尾部插入
bool Linklist_push_back(PLNode l, ElemType *e)
{
    if((l == NULL) || (e == NULL)) 
    {
        printf("链表l或元素e为空\n");
    }

    PLNode now;
    PLNode end = (PLNode)malloc(sizeof(LNode));
    memcpy(&(end->data), e, sizeof(e));
    end->next = NULL;
    now = l;
    //找到最后一个节点
    while (now->next != NULL)
    {
        now = now->next;
    }
    now->next = end;
    
    return true;
}

//单链表定位，查找链表中第一个值与e相等的节点，如果找得到返回该节点
LNode *Linklist_location(const LNode *l, ElemType *e)
{
    LNode *now = l;
    while(now->next)
    {
        if(now->data == *e) 
        {
            return now;
        }
        now = now->next;
    }
    return NULL;
}

//单链表定位，查找链表中第一个值与e相等的节点，如果找得到返回该节点在整个链表顺序
int Linklist_locate_pos(const LNode *l,ElemType *e)
{
    int index = 1;
    PLNode p = l->next;
    while(p->next != NULL)
    {
        if(!memcmp(&p->data, e, sizeof(ElemType)))
            return index;

        index++;
        p = p->next;
    }

    return -1;
}

//单链表前插元素操作，在第i位前插入元素e
//为兼容结构体，此处传递的e采用地址的形式
//但直接传入19920522这样的常量进入就不行？
//常量无法正常取到地址吗？
bool Linklist_insert_my(LNode *l, int i ,ElemType *e)
{
    if(Linklist_length(l) < i) 
    {
        printf("前插位置大于链表长度！\n");
    }
    int index = 1;
    PLNode p = l->next;
    while(p->next)
    {
        if(index+1 == i)
            break;
        p = p->next;
        index++;
    }

    PLNode temp = (PLNode)malloc(sizeof(LNode));
    if(temp == NULL)
    {
        printf("分配内存失败！\n");
    }
    temp->data = *e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

//单链表后插元素操作，在第i位后插入元素e
bool Linklist_push(LNode *l, int i, const ElemType *e)
{
    if(Linklist_length(l) < i)
    {
        printf("后插序号大于链表长度！\n");
        return false;
    }

    PLNode temp;
    PLNode now = l->next;
    int index = 1;
    while(now->next)
    {
        if(index == i){
            break;
        }
        index++;
        now = now->next;
    }

    temp = (LNode*)malloc(sizeof(LNode));
    if(temp == NULL) return false;
    temp->data = *e;
    temp->next = now->next;
    now->next = temp;
    return true;
}

//单链表删除元素操作，删除能找到的第一个指定元素
bool Linklist_delete_ElemType(LNode *l, const ElemType *e)
{
    LNode *now = l->next;
    while(now->next)
    {
        if(!memcmp(&now->next->data, e, sizeof(ElemType)))
            break;
        now = now->next;
    }

    if(now->next == NULL) return false;
    //如果没有这个temp的话，就会造成直接释放错误的now->next
    PLNode temp = now->next;
    now->next = now->next->next;
    free(temp);
    return true;
}

