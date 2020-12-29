# include <iostream>
# include <vector>
using namespace std;

// 滑动窗口
// 写不出来呜呜呜～
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sum = 0, result = INT16_MAX;
        int l = 0, r = 0;
        while (r < nums.size()) {
            sum += nums[r];
            result = max(result, sum);
            while (l <= r && sum <= 0) {
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return result;
    }
};

// 动态规划
// L(n) = L(n-1) + nums[n], L(n-1) >= 0
//      || nums[n], L(n-1) < 0
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int dp[size+1];
        dp[1] = nums[0];
        int result = nums[0];
        for (int i = 1; i < size; i++) {
            if (dp[i-1] >= 0) dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
            result = max(dp[i], result);
        }
        return result;
    }
};