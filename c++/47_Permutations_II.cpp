# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// 全排列，很难，要好好理解体会
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> cmb;
        bool used[nums.size()] = {false};
        sort(nums.begin(), nums.end());
        backTracing(v, nums, cmb, used);
        return v;
    }

    void backTracing(vector<vector<int>>& v, vector<int>& nums, vector<int>& cmb, bool *used) {
        if (cmb.size() == nums.size()) {
            v.push_back(cmb);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 和上一个一样，并且上一个没有用过，则是重复；如上一个用过，则代表是同一棵子树(0,0,9)
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            // 用过则跳过，用于避免单个数字的重复
            if (used[i]) continue;
            used[i] = true;
            cmb.push_back(nums[i]);
            backTracing(v, nums, cmb, used);
            cmb.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums({0, 0,9});
    vector<vector<int>> v = s.permuteUnique(nums);
    cout << v.size() << endl;
    for (vector<int> n : v) {
        for (int x : n)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}