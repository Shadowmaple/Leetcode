# include <iostream>
# include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, r = 0;
        int res = -101, cur = 0;
        while (r < nums.size()) {
            cur += nums[r];
            while (l < r && cur < nums[r]) {
                cur -= nums[l];
                l++;
            }
            res = max(res, cur);
            r++;
        }
        return res;
    }
};

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};