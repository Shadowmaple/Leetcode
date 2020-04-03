# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> v;
        int len = mat.size();
        int num[len];
        for (int i = 0; i < len; i++) {
            num[i] = 0;
            for (int j : mat[i])
                if (j) num[i]++;
        }
        for (int i = 0; i < k; i++) {
            int min = 9999, x = 0;
            for (int j = 0; j < len; j++) {
                if (num[j] != -1 && num[j] < min) {
                    x = j;
                    min = num[j];
                }
            }
            num[x] = -1;
            v.push_back(x);
        }

        return v;
    }
};