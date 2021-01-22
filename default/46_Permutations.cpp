# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        backTracing(v, nums, nums.size(), 0);
        return v;
    }

    void backTracing(vector<vector<int>>& v, vector<int>& nums, int len, int idx) {
        if (idx == len) {
            v.push_back(nums);
            return ;
        }

        for (int i = idx; i < len; i++) {
            swap(nums[i], nums[idx]);
            backTracing(v, nums, len, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};