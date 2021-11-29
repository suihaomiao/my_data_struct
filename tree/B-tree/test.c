#include "Btree.h"

int main()
{
    char *s = {"(A(B(D,E),C(F,G)))"};

    //bitnode_t *t = Bitnode_creat(s);
    bitnode_t *t;
    Bitnode_creat_char(&t);
    Bitnode_preoder_traverse(t);
    printf("       前序遍历");
    printf("\n");
    Bitnode_inoder_traverse(t);
    printf("       中序遍历");
    printf("\n");
    Bitnode_postoder_traverse(t);
    printf("       后序遍历");
    printf("\n");
}