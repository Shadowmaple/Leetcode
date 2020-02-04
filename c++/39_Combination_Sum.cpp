# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> cmb;
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

        for (; idx >= 0; idx--) {
            vector<int> x = cmb;
            x.push_back(array[idx]);
            backTrace(v, x, array, num-array[idx], idx);
        }
    }
};