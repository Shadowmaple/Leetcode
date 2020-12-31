# include <iostream>
# include <vector>
using namespace std;

// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int sum = nums[l] + nums[r];
            if (sum == target)
                return vector<int>{nums[l], nums[r]};
            if (sum > target) r--;
            else l++;
        }
        return vector<int>{};
    }
};