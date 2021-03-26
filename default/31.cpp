# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return ;

        int i = size-1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        // 不存在下一个更大的排列
        if (i == 0) {
            sort(nums.begin(), nums.end());
            return ;
        }
        // 获取右部比 nums[i-1] 大的最小的值
        int tar = i;
        for (int j = i+1; j < size; j++) {
            if (nums[j] > nums[i-1] && nums[j] < nums[tar])
                tar = j;
        }
        // 交换
        swap(nums[i-1], nums[tar]);
        // 右部排序
        sort(nums.begin() + i, nums.end());
    }
};