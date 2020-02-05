# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    int len;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cmb;
        len = nums.size();
        backTracing(nums, cmb);
        return v;
    }

    void backTracing(vector<int>& nums, vector<int>& cmb) {
        if (cmb.size() == len) {
            v.push_back(cmb);
            return ;
        }

        for (int idx = 0; idx < len; idx++) {
            if (nums[idx] == ' ') continue;
            vector<int> x = cmb, y = nums;
            x.push_back(nums[idx]);
            y[idx] = ' ';
            backTracing(y, x);
        }
    }
};