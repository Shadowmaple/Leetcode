# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cmb;
        DFS(cmb, k, n, 1);
        return v;
    }

    void DFS(vector<int>& cmb, int k, int n, int num) {
        if (!n && !k) {
            v.push_back(cmb);
            return ;
        } else if (!n || !k) {
            return ;
        }

        for (int i = num; i <= 9; i++) {
            if (n < i) continue;
            cmb.push_back(i);
            DFS(cmb, k-1, n-i, i+1);
            cmb.pop_back();
        }
    }
};