# include <iostream>
using namespace std;

// 动态规划
// L(n) =
//   max(i * L(n-i)), L(n-i) >= n-i
//   max(i * (n-i), L(n-i) < n-i
// 其中 1<=i<=n/2
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 2) return 1;

        int dp[n+1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i/2; j++) {
                if (dp[i-j] >= i-j)
                    dp[i] = max(dp[i], j*dp[i-j]);
                else dp[i] = max(dp[i], j*(i-j));
            }
        }
        return dp[n];
    }
};