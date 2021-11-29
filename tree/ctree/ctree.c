#include "ctree.h"

//树的初始化
void Ctree_init(ctree_t *t)
{
    t->parent = NULL;
    for (int i = 0; i < MAX_SON; i++)
    t->son[i] = NULL;
}

//创建一个树
//S是广义表形式表示的树，如：(A(B(E(J),F),C(G(K,L)),D(H,I)))
ctree_t *Ctree_creat(TElemType *s)
{

    //对于广义表形式表示的树，原则是遇到（进栈，）出栈；
    //在（）括号之间的是子节点,遇到,是另一个子节点
    //因此思路为声明两个数组-stack和d来表示栈（其实是数组，用top下标来表示栈）
    ctree_t *t = NULL; //在函数内创建树的根节点
    ctree_t *stack[MAX_TREE], *temp;
    int i = 0, top = -1;
    int d[MAX_SON];
    while (s[i]) 
    {
        switch (s[i])
        {
        case ' ': 
        break;
        case '(': //进栈，把temp压进栈，同时d[]表示第几个子节点，此时还没有任何一个子节点，因此d[top] = 0;
            top++; 
            stack[top] = temp;
            d[top] = 0;
            break;
        case ')': //出栈，父节点的子节点均已处理完，开始处理上一级的子节点
            top--;
            break;
        case ',': 
            d[top]++;
            break;
        default:
            temp = (ctree_t *)malloc(sizeof(ctree_t));
            memcpy(&temp->data, s + i, sizeof(TElemType));
            for (int i = 0; i < MAX_SON; i++)
                temp->son[i] = NULL;
            if (!t) 
                t = temp; //如果t首节点还没初始化，就把刚才初始化的当做首节点
            else
            {
                //parent和son都是指针，可以直接赋值
                //temp的父节点是stack[top]
                temp->parent = stack[top];
                //stack[top]的第d[top]个子节点是temp
                stack[top]->son[d[top]] = temp;
            }
        }
            i++;
    }
    return t;
    //printf("&t = %p\n", t);
} //遇到括号的问题，遍历时需要用到栈

//访问树的元素
//在树t中寻找元素e，找到返回0，反之返回-1
int Ctree_search(ctree_t *t, TElemType *e)
{
    if (!memcmp(&t->data, e, sizeof(TElemType))) 
        return 0;
    for (int i = 0; i < MAX_SON; i++)
    {
        //如果有子节点才去寻找
        if (t->son[i] == NULL) 
            break;
        //递归调用，如果找得到就返回0，找不到就继续
        if (!Ctree_search(t->son[i], e)) 
            return 0;
    }
    //子节点都递归完成后，依然无法返回，意味着无法找到，返回-1
    return -1;
}

//遍历打印树
//(A(B(E(J),F),C(G(K,L)),D(H,I)))
void Ctree_print(ctree_t *t)
{
    //按照广义表的形式来打印树结构
    if (t)
    {
        printf("(%c", t->data);
        for (int j = 0; j < MAX_SON; j++)
        {
            if (!t->son[j]) 
                break;
            if (!(t->son[j]))
                break;
            if (j != 0)
                printf(",");
            if (j == 0)
                printf("(");
            Ctree_print(t->son[j]);
        }
        printf(")");
    }
}

//树的深度
int Ctree_deepth(ctree_t *t)
{
    if(!t) 
        return 0;
    else
    {
        int max = 0;
        for(int i = 0; i < MAX_SON; i++)
        {
            int k = Ctree_deepth(t->son[i]);
            if(k > max)
                max = k;
        }
        return max + 1;
    }
}

//销毁树
void Ctree_destroy(ctree_t *t)
{
    for(int i = 0; i < MAX_SON; i++)
    {
        if(!t->son[i])
            continue;
        Ctree_destroy(t->son[i]);
    }
    free(t);
}

//判断为空树
//返回0为空，其他为非空
int Ctree_empty(ctree_t *t)
{
    if(!t) return 0;
    return -1;
}

//返回树的根
ctree_t *Ctree_root(ctree_t *t)
{
    if(!t) return NULL;
    if(!t->parent) return t;
    return Ctree_root(t->parent);
}

//在某个节点处插入孩子
//成功返回0，失败返回-1；
int Ctree_insert_node(ctree_t *t, TElemType *e)
{
    if(!t) return -1;
    int i,flag = 0;
    for(i = 0; i < MAX_SON; i++)
    {
        if(!t->son[i]) {
            flag++;
            break;
        }
    }
    if(flag > 0)
    {
        ctree_t *tmp = (ctree_t *)malloc(sizeof(ctree_t));
        tmp->parent = t;
        for(int j = 0; j < MAX_SON; j++)
        {
            tmp->son[j] = NULL;
        }
        memcpy(&tmp->data, e, sizeof(TElemType));
        //t的子节点需要继续添加
        //printf("i = %d\n",i);
        t->son[i] = tmp;
        return 0;
    }
    else
    {
        printf("节点%c子节点已满！无法继续添加\n",t->data);
        return -1;
    }
    
}

//在某个节点处插入树
//成功插入返回0，失败返回-1
int Ctree_insert_tree(ctree_t *t, ctree_t *child)
{
    //插入节点和插入子树应该是一样的
    if(!t) return -1;
    int i,flag = 0;
    for(i = 0; i < MAX_SON; i++)
    {
        if(!t->son[i]) {
            flag++;
            break;
        }
    }
    if(flag > 0)
    {
        child->parent = t;
        //t的子节点需要继续添加
        //printf("i = %d\n",i);
        t->son[i] = child;
        return 0;
    }
    else
    {
        printf("节点%c子节点已满！无法继续添加\n",t->data);
        return -1;
    }
}

//寻找树中的节点
ctree_t *Ctree_search_node(ctree_t *t, ctree_t *node)
{
    if(!t) return NULL;
    if(!memcmp(&t->data, &node->data, sizeof(TElemType))) return node;
    int i;
    ctree_t *tmp;
    for(i = 0; i < MAX_SON; i++)
    {
        if(!t->son[i])
            continue;
        tmp = Ctree_search_node(t->son[i], node);
        if(tmp) return t;
    }
    return NULL;
}

//给某节点赋值
int Ctree_assign(ctree_t *t, ctree_t *e,TElemType value)
{
    ctree_t *tmp = Ctree_search_node(t, e);
    if(!e) return -1;
    else
    {
        memcpy(&e->data, &value, sizeof(TElemType));
    }
    return 0;
}
