#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉树Binary-Tree
//特点如下：
//1、每个节点最多两颗子树
//2、左子树和右子树是有顺序的，不能随意颠倒（即使某个节点只有一颗子树，也要区分左还是右）
//再次强调，二叉树要严格区分左右，即一个节点只有左节点和一个节点只有右节点，是不一样的

//满二叉树
//每个分支均存在左、右节点，且所有的叶子都在同一层。

//二叉树的性质
//性质1：在二叉树的第i层上至多有2^(i-1)个节点
//性质2：深度为k的二叉树，最多有2^k-1个节点
//性质3：对于任意一个二叉树，如果其终端节点数为n0，度为2的节点数为n2，则n0=n2+1
//性质4：具有n个节点的完全二叉树的深度为[log2 n]+1；
//性质5：如果对于一个n个节点的完全二叉树，（其深度为[log2 n]+1），按照层数进行排序：
//1）如果i = 1，则该节点为根节点；如果i>1，该节点的双亲为[i/2]；[x]表示为不大于x的最大整数
//2）如果2i > n;则节点i无左孩子（节点i为叶子节点），否则，其左孩子是节点2i
//3）如果2i+1 > n，则节点无右孩子；否则其右孩子是节点2i+1

#define MAX_SIZE 100

typedef char ElemType;

typedef struct BITNODE
{       
    struct BITNODE *lchild;
    struct BITNODE *rchild; 
    struct BITNODE *parent;
    ElemType data;
}bitnode_t;

//二叉树的遍历是指从根节点出发，按照某种次序依次访问二叉树中所有节点，使得每次节点都被访问一次；
//关键是：访问和次序；
//1、前序遍历，先访问根节点，然后遍历左树，再遍历右树。-Ctree的search采用的是前序遍历
//2、中序遍历，从根节点开始，（不是访问根节点）先遍历左子树，然后访问根节点，最后访问右节点。
//3、后序遍历，从左到右线叶子节点的方式，遍历左子树再遍历右子树，最后是根节点
//4、层序遍历，从根节点开始，一层一层往下遍历。

//如果知道了某个顺序遍历的结果
//应该可以推导出整个树的形状
//已知前序和中序，可以推导
//已知后序和中序，可以推导
//全靠一手脑补，记住前序，中序和后序的遍历过程（取名字还是有意义的）


//初始化创造一个二叉树
bitnode_t *Bitnode_creat(char *s);

//前序遍历
void Bitnode_preoder_traverse(bitnode_t *t);

//中序遍历
void Bitnode_inoder_traverse(bitnode_t *t);

//后序遍历
void Bitnode_postoder_traverse(bitnode_t *t);

//创建树
void Bitnode_creat_char(bitnode_t **t);



#endif 