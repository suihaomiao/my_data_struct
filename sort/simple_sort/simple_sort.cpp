#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int a, int b)
{
    if(a == b) return;
    int t;
    t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

//简单排序，同样两层循环，第一层遍历所有元素
//第二层循环从第一层循环作为起点，找到最小值（降序排列找到最大值）
//回到第一层循环后，把最小值和当前值交换位置即可。
//时间复杂度O(n^2)，空间复杂度O(1),算法不稳定，因为在交换位置时，相同元素的相对位置可能发生改变
void simple_sort(vector<int> &nums)
{
    int mins, size = nums.size();
    for(int i = 0; i < size-1; ++i)
    {
        mins = i;
        for(int j = i; j < size; ++j)
        {
            if(nums[mins] > nums[j])
                mins = j;
        }
        if(mins != i)
            swap(nums, i, mins);
    }
}


int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    simple_sort(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}