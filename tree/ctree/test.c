#include "ctree.h"

//(A(B(E(J),F),C(G(K,L)),D(H,I)))

int main()
{
    //printf("123");
    TElemType *s = {"(A(B(E(J),F),C(G(K,L)),D(H,I)))"};

    ctree_t *t = Ctree_creat(s);
    //printf("&t = %p\n", &t);
    // printf("t->data = %c\n", t->data);
    // printf("t->son[0]->data = %c\n", t->son[0]->data);
    // printf("t->son[0]->son[0]->data = %c\n", t->son[0]->son[0]->data);
    // printf("t->son[0]->son[1]->data = %c\n", t->son[0]->son[1]->data);
    // printf("t->son[0]->son[0]->son[0]->data = %c\n", t->son[0]->son[0]->son[0]->data);
    // printf("A的第三个子节点是:%c\n", t->son[2]->data);
    // printf("A的第三个子节点的子节点是:%c\n", t->son[2]->son[0]->data);
    // printf("A的第三个子节点的子节点是:%c\n", t->son[2]->son[1]->data);
    TElemType e = 'Z';
    if(!Ctree_insert_node(t->son[0], &e))
    {
        printf("在节点%c成功插入节点%c\n",t->son[0]->data,e);
    }
    char *str = {"(M(N(I)))"};
    ctree_t *tmp = Ctree_creat(str);
    Ctree_print(tmp);
    printf("\n");
    if(!Ctree_insert_tree(t->son[1], tmp))
    {
        printf("在节点%c成功插入子树%c\n",t->son[1]->data, tmp->data);
    }
    Ctree_print(t);
    printf("\n");
    if(!Ctree_assign(t, t->son[2], 'T'))
    {
        printf("成功替换节点！\n");
    }
    Ctree_print(t);
    printf("\n");
    if (!Ctree_search(t, &e))
        printf("%c在树中可以找到！\n", e);
    else
    {
        printf("%c无法在树中可以找到！\n", e);
    }
    printf("树的深度为:%d\n",Ctree_deepth(t));
    printf("节点%c的根为：%c\n",t->son[0]->son[0]->son[0]->data,Ctree_root(t->son[0]->son[0]->son[0])->data);
    Ctree_destroy(t);

}
