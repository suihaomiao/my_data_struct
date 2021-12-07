#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//归并排序
//采用分治思想，意思是把一个长度为n的数组，拆分成两个长度为n/2的数组来解决
//然后继续拆分，用递归的思想解决问题
//最后再把两段数组给合并到一起
void merge_sort(vector<int> &nums, int l, int r,vector<int> &temp)
{
    if(l +1 >= r) 
        return;

        int mid = (l+r) >> 1;
        merge_sort(nums, l, mid, temp);
        merge_sort(nums, mid, r, temp);
        //merge(nums, l, mid, r);
        int p = l, q = mid, i = l;
        while(p < mid || q < r)
        {
            //此处其实是作为合并两个数组的简单判据
            //如果在q>=r的情况下，直接把p指向的值赋值即可。temp[i++] = nums[p++];
            //如果q<r时，就去判断p小于mid 且nums[p] <= nums[q]
            if(q  >= r || (p < mid && nums[p] <= nums[q]))
            {
                temp[i++] = nums[p++];
            }else{
                temp[i++] = nums[q++];
            }
        }
        for(int i = l; i < r; ++i)
        {
            nums[i] = temp[i];
        }
}

int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    vector<int> temp(nums.size());    
    merge_sort(nums,0, nums.size(),temp);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}