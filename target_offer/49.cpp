# include <iostream>
# include <vector>
using namespace std;

// 有点动态规划的思想
// 三指针
class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> v{1};
        for (int idx = 2; idx <= n; idx++) {
            int temp = min(v[i]*2, min(v[j]*3, v[k]*5));
            v.push_back(temp);
            if (temp == v[i]*2) i++;
            if (temp == v[j]*3) j++;
            if (temp == v[k]*5) k++;
        }
        return v[n-1];
    }
};