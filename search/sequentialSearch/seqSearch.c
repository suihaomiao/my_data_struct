#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//顺序查找，a为数组，n为数组容量，key为查找的关键字
//这是最简单的查找方法
int Sequential_Search(int *a, int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(!memcmp(a+i, &key, sizeof(key)))
            return i;
    }
    return -1;
}

//优化：哨兵查找
//将key赋值给a[0]，然后从末尾开始查找，避免每次循环的i需要跟n比较大小
//函数返回0表示失败，如果就是0位置的值==key？
//只能在函数外部进行简单的判断a[0] == key?
int Sequential_Search2(int *a, int n, int key)
{
    int i;
    a[0] = key;
    i = n;
    while(a[i] != key)
    {
        i--;
    }
    return i;
}

//折半查找
//适用于有序表，即表中元素均从大到小或从小到大排列；
//（默认从小到大排列）将key与表中间记录的值相比，如果key大则在右半区继续查找，反之则在左半区查找
//不断递归即可？
//注意边界条件：1、找到关键字key == a[i];2、已经无法划分区域，即只剩下一个元素n==1;
//我真的是傻逼，可能是二叉树学完了，递归的思想深入脑海；
//其实用一个双指针即可（指向首段和末端的int即可）；
int Binary_Search(int *a, int n, int key)
{
    // int i = n/2;
    // if(i == 0) reutrn -1;
    // if(key = a[i]) return i;
    // if(key < a[i])
    // {
    //     return Binary_Search(a, i, key);
    // }
    // else{
    //     return Binary_Search(a+i, n - i, key);
    // }
    int low, high, mid;
    low = 1;
    high = n;
    while(low <= high)
    {
        //插值查找法
        //mid = low + (high - low) * (key - low) / (a[high] - a[low]);
        //核心点在于(key - low) / (high - low)，此举意味着判断key在整个数组分布大致在哪一块，可以迅速定位到key可能在的部分
        //插值查找法与折半查找原理相似，仅仅在mid的计算上有所不同；
        //但仅限于比较均匀分布且下标较大的数组，如果是分均匀分布的话，该方法不适用
        mid = (high+low) /2;
        //key小于中间数，则把high移动到mid-1
        if(key < a[mid])
        {
            high = mid - 1;
        }
        //key大于中间数，则把low移动到mid+1
        else if(key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            //如果相等，就返回mid
            return mid;
        }
    }
    
    //返回0，则说明未找到
    return 0;
}


int main()
{
    int a[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int key,index;
    scanf("%d", &key);

    if((index = Sequential_Search(a, 20, key)) >= 0)
    {
        printf("%d在数组a中能被找到，其位置为%d\n",key, index);
    }
    else
    {
        printf("%d在数组a中无法被找到\n",key);
    }

    if(a[0] == key)
    {
        printf("%d在数组a中能被找到，其位置为0\n",key);
        return 0;
    }
    index = Sequential_Search2(a, 10, key);
    if(index == 0)  printf("%d在数组a中无法被找到\n",key);
    else{
        printf("%d在数组a中能被找到，其位置为%d\n",key, index);
    }

    index = Binary_Search(a, 20, key);
    if(index == 0)
    {
        printf("折半查找无法在数组a找到%d\n",key);
    }
    else
    {
        printf("折半查找在数组a的第%d位找到%d\n",index,key);
    }

}




