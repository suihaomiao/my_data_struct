#include "BiThrTree.h"


int main()
{
    pbitree_t t;
    //前序遍历输入：124###35##6##
    printf("前序遍历输入：\n");
    BitThrTree_creat_char(&t);
    printf("start call BitThrTree_inthreading\n");
    BitThrTree_inthreading(t);
    printf("start call BitThrTree_inorder_treverse\n");
    BitThrTree_inorder_treverse(t);
    //中序线索化后，以链表方式输出为：4 2 1 5 3 6

    printf("\n");
}