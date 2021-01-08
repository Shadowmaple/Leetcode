# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (nums[r] > target) r--;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) return vector<int>{nums[l], nums[r]};
            else if (sum < target) l++;
            else r--;
        }
        return vector<int>{};
    }
};