#include <iostream>
#include <vector>

using namespace std;

//快速排序
//第一步，在数组中选取一个基准值，将小于该值的其他数放到数组左边；大于该值的其他数放到数组的右边
//然后分别继续迭代左边部分和右边部分

int partition(vector<int> &nums, int low, int high)
{
    //if (low >= high return 0;
    int pivot = nums[low];
    while(low < high)
    {
        //移动high指针，让high指向第一个不小于pivot的数
        while(low < high && nums[high] >= pivot){
            --high;
        }
        //填坑
        if(low < high) 
            nums[low] = nums[high];
        //从low部分开始移动填坑
        while(low<high && nums[low] <= pivot){
            ++low;
        }
        //填坑
        if(low < high) 
            nums[high] = nums[low];
    }

    //把基准数放到合适的位置
    nums[low] = pivot;
    //返回的是基准数的索引
    return low;
}

void my_quick_sort(vector<int> &nums, int low, int high)
{
    //low < high 是出递归的条件
    if(low < high)
    {
        int index = partition(nums, low, high);
        //cout << "index = " << index << endl;
        my_quick_sort(nums, low, index -1);
        my_quick_sort(nums, index+1, high);
    }
}


int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    my_quick_sort(nums, 0, nums.size()-1);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}