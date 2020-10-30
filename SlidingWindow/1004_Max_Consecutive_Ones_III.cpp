# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0;
        int cost = K;
        int len = 0;
        while (r < A.size()) {
            if (A[r] == 1) {
                r++;
                continue;
            } else if (cost > 0) {
                cost--;
                r++;
                continue;
            }
            len = max(len, r - l);
            while (l < r && A[l] == 1) l++;
            if (A[l] == 0) {
                cost++;
                l++;
            }
        }
        return max(len, r - l);
    }
};