# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> cmb;
        sort(candidates.begin(), candidates.end()); // 排序，用于去重
        backTrace(v, cmb, candidates, target, candidates.size()-1);
        return v;
    }

    void backTrace(vector<vector<int>>& v, vector<int>& cmb, vector<int>& array, int num, int idx) {
        if (!num) {
            v.push_back(cmb);
            return ;
        } else if (num < 0) {
            return ;
        }

        // 记录最后一次的数，用于去重
        int pre = -1;
        for (; idx >= 0; idx--) {
            if (array[idx] == pre) continue;
            pre = array[idx];
            vector<int> x = cmb;
            x.push_back(array[idx]);
            backTrace(v, x, array, num-array[idx], idx-1);
        }
    }
};