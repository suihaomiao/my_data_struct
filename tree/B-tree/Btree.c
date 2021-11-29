#include "Btree.h"

//初始化创造一个二叉树
//"(A(B(D,E),C(F,G)))"
bitnode_t *Bitnode_creat(char *s)
{
    bitnode_t *stack[MAX_SIZE], *temp,*t = NULL;
    int top = -1, i = 0, left;
    while(s[i])
    {
        switch (s[i])
        {
        case ' ':
            //遇到空格直接跳过
            break;
        case '(':
            //遇到左括号压进栈，此时是父节点
            top++;
            stack[top] = temp;
            left = 1;
            break;
        case ')':
            //遇到右括号出栈
            top--;
            break;

        case ',':
            //逗号表示右节点，left是左节点的表示
            left = 0;
            break;
        default:
            temp = (bitnode_t *)malloc(sizeof(bitnode_t));
            if(!temp){
                printf("初始化分配内存失败！\n");
                return NULL;
            }
            memcpy(&temp->data, s + i, sizeof(ElemType));
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->parent = NULL;
            if(t == NULL)
            {
                t = temp;
            }else
            {
                if(left == 0)
                {
                    stack[top]->rchild = temp;
                    temp->parent = stack[top];
                }else
                {
                    stack[top]->lchild = temp;
                    temp->parent = stack[top];                   
                }
            }
            break;
        }
        i++;
    }
    return t;
}

//前序遍历
void Bitnode_preoder_traverse(bitnode_t *t)
{
    if(t == NULL) return;
    printf("%c ",t->data);
    Bitnode_preoder_traverse(t->lchild);
    Bitnode_preoder_traverse(t->rchild);
}

//中序遍历
void Bitnode_inoder_traverse(bitnode_t *t)
{
    if(t == NULL) return;
    Bitnode_inoder_traverse(t->lchild);
    printf("%c ",t->data);
    Bitnode_inoder_traverse(t->rchild);
    return;
}

//后序遍历
void Bitnode_postoder_traverse(bitnode_t *t)
{
    if(t == NULL) return;
    Bitnode_postoder_traverse(t->lchild);
    Bitnode_postoder_traverse(t->rchild);
    printf("%c ",t->data);
    return;
}

//创建树
void Bitnode_creat_char(bitnode_t **t)
{
    ElemType ch;
    scanf("%c",&ch);
    if(ch == '#')
        *t = NULL;
    else{
        *t = (bitnode_t *)malloc(sizeof(bitnode_t));
        if(*t == NULL)
        {
            printf("初始化内存失败！\n");
            return;
        }
        //memcpy(&(*t)->data, &ch, sizeof(ElemType));
        (*t)->data = ch;
        Bitnode_creat_char(&(*t)->lchild);
        Bitnode_creat_char(&(*t)->rchild);
    }
}
