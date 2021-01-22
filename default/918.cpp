# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int res = A[0], minNum = A[0];
        int pre = A[0], minPre = A[0], sum = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (A[i] + pre < A[i]) pre = A[i];
            else pre = A[i] + pre;
            res = max(pre, res);

            if (A[i] + minPre > A[i]) minPre = A[i];
            else minPre = A[i] + minPre;
            minNum = min(minNum, minPre);

            sum += A[i];
        }
        // 全为负数情况，即最小子数组为全数组，但是必须最大子数组要有一个值
        if (minNum == sum) return res;
        return max(res, sum - minNum);
    }
};