# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int l = 0, r = 0;
        int count = 0;
        bool isBiger = true; // 上一次的比较
        while (r < A.size()-1) {
            if (l == r) {
                if (A[r] == A[r+1]) {
                    l = ++r;
                    continue;
                }
                isBiger = A[r] > A[r+1];
                ++r;
                continue;
            }
            if (!isBiger && A[r] > A[r+1] || isBiger && A[r] < A[r+1]) {
                isBiger = !isBiger;
                ++r;
                continue;
            }
            count = max(count, r - l + 1);
            l = r;
        }
        return max(count, r - l + 1);
    }
};