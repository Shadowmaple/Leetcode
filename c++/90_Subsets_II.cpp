# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    bool *used;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cmb;
        used = new bool[nums.size()]{};
        sort(nums.begin(), nums.end());
        backTracking(cmb, nums, 0);
        return v;
    }

    void backTracking(vector<int>& cmb, vector<int>& nums, int idx) {
        v.push_back(cmb);
        for (int i = idx; i < nums.size(); i++) {
            if (i > 0 && !used[i-1] && nums[i] == nums[i-1]) continue;
            used[i] = true;
            cmb.push_back(nums[i]);
            backTracking(cmb, nums, i+1);
            cmb.pop_back();
            used[i] = false;
        }
    }
};