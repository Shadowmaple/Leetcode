# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cmb;
        backTracking(cmb, n, k, 1);
        return v;
    }

    void backTracking(vector<int>& cmb, int n, int k, int idx) {
        if (!k) {
            v.push_back(cmb);
            return ;
        }

        for (int i = idx; i <= n; i++) {
            cmb.push_back(i);
            backTracking(cmb, n, k-1, i+1);
            cmb.pop_back();
        }
    }
};