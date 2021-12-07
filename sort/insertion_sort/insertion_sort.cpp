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

//插入排序，也分为两次循环
//第一层循环遍历每个元素，注意从1开始遍历，原因还是因为第二层循环
//第二层循环，开始从第一层循环作为起点，向前遍历，如果发现j > 0 && nums[j] < nums[j-1]，交换j和j+1的位置
//循环下来，可以发现，最小值会一直往左边方向走
//算法时间复杂度为O(n^2),空间复杂度为O（1），相同元素的相对位置不会发生改变，算法稳定
void insertion_sort(vector<int> &nums)
{
    int size = nums.size();
    int index;
    for(int i = 1; i < size; ++i)
    {
        index = i;
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j)
        {   
            swap(nums, j, j-1);
        }
    }
}

int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    insertion_sort(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
