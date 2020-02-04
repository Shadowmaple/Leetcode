# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> cmb;
        set<vector<int>> s;
        backTrace(s, cmb, candidates, target, candidates.size()-1);
        for (vector<int> x : s)
            v.push_back(x);

        return v;
    }

    void backTrace(set<vector<int>>& s, vector<int>& cmb, vector<int>& array, int num, int idx) {
        if (!num) {
            sort(cmb.begin(), cmb.end());
            s.insert(cmb);
            return ;
        } else if (num < 0) {
            return ;
        }

        while (idx >= 0) {
            vector<int> x = cmb;
            x.push_back(array[idx]);
            backTrace(s, x, array, num-array[idx], idx-1);
            idx--;
        }
    }
};