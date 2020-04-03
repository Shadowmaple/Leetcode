# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cmb;
        backTracing(nums, cmb, 0);
        return v;
    }

    void backTracing(vector<int>& nums, vector<int>& cmb, int idx) {
        v.push_back(cmb);
        for (int i = idx; i < nums.size(); i++) {
            cmb.push_back(nums[i]);
            backTracing(nums, cmb, i+1);
            cmb.pop_back();
        }
    }
};