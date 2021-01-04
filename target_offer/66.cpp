# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size());
        int cur = 1;
        // 先乘左边
        for (int i = 0; i < a.size(); i++) {
            res[i] = cur;
            cur *= a[i];
        }
        cur = 1;
        // 再乘右边
        for (int i = a.size()-1; i >= 0; i--) {
            res[i] *= cur;
            cur *= a[i];
        }
        return res;
    }
};