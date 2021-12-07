#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int a, int b)
{
    int t;
    t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

//下沉式，建堆--对应的是大顶堆，
void max_heapify(vector<int> &nums, int start, int end)
{
    //建立父节点和子节点的指针
    int dad = start;
    int son = start * 2 +1;
    while(son <= end)
    {
        //此处一定要是son + 1 <= end，否则容易在end很小的时候，漏掉右节点
        if(son +1 <= end && nums[son] < nums[son + 1])//左右节点做比较，选择大的
            ++son;
        if(nums[son] < nums[dad])//如果子节点小于父节点，就return 
            return;
        else{   //否则就交换父节点和字节点，继续循环
            swap(nums, dad, son);
            dad = son;
            son = dad *2 +1;
        }
    }
}

//堆排序
void heap_sort(vector<int> &nums, int len)
{
    //从最后一个父节点开始调整
    //因为叶子节点不会有子节点，不需要进行调整
    for(int i = len/2 -1; i >= 0; --i)
    {
        max_heapify(nums, i, len - 1);
    }
    //因为是大顶堆结构，所以0位置一定是最大值
    //首先吧0和最后一位交换位置，然后重新构建大顶堆
    for(int i = len - 1; i >= 0; --i)
    {
        swap(nums, 0, i);
        max_heapify(nums, 0, i - 1);
    }
}

int main()
{
    //vector<int> nums = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    heap_sort(nums, nums.size());
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}