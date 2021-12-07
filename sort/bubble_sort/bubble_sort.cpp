#include <iostream>
#include <vector>

using namespace std;

//冒泡排序法
//比较简单的一种排序方法，采用双层遍历的方式
//第一层遍历：数组中每个元素均遍历（元素中最后一个元素不用遍历，因为在第二层遍历）
//第二层遍历：从0开始相邻的两个数进行比较，如果后者较大就交换位置（对应升序排列，如果降序则相反处理即可）
//第二层遍历的末尾是size-i-1；因为第一层每次循环一次，就有一个当前的最大数放到了数组的尾部，因此不需要循环后面

void swap(vector<int> &nums, int a, int b)
{
    int t;
    t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

//冒泡排序因为双层循环，所以时间复杂度为O(n^2),空间复杂度因为没有占用额外的空间，所以为O（1）
//且冒泡排序因为仅当nums[j] > nums[j+1]才会交换位置，当nums[j] = nums[j+1]时不变，所以是稳定的
void bubble_sort(vector<int> &nums)
{
    int size = nums.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(nums[j] > nums[j+1])
                swap(nums,j,j+1);
        }
    }
}

int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    bubble_sort(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}