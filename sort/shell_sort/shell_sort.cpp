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

//没写出来，暂时没啥思路
void shell_sort(vector<int> &nums)
{
    int size = nums.size();
    int increment = size;
    int i,j,k;
    while(increment >= 1)
    {
        increment = increment / 2;
        for(i = 0; i < increment; ++i)
        {
            for(j = i + increment; j < size; j += increment)
            {   
                if(nums[j - increment] > nums[j])
                {
                    int temp = nums[i];
                    k = j - increment;
                    while(k >= 0 && nums[k] > temp)
                    {
                        nums[k + increment] = nums[k];
                        k -= increment;
                    }
                    nums[k] = temp;
                }
            }
        }
    }
}

int main()
{
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    shell_sort(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}