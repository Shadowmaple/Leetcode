# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    bool *used;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cmb;
        v.push_back(cmb);
        used = new bool[nums.size()]{};
        backTracing(nums, cmb, 0);
        return v;
    }

    void backTracing(vector<int>& nums, vector<int>& cmb, int idx) {
        if (idx == nums.size()) {
            return ;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            cmb.push_back(nums[i]);
            v.push_back(cmb);
            backTracing(nums, cmb, i+1);
            cmb.pop_back();
            used[i] = false;
        }
    }
};