# include <iostream>
using namespace std;

// 动态规划
// 主要要考虑0
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (s[0] == '0') return 0;
        int dp[len+1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= len; i++) {
            string x = s.substr(i-2, 2);
            if (s[i-1] == '0') {
                if (x == "00" || x >= "30") return 0;
                dp[i] = dp[i-2];
            } else if (s[i-2] != '0' && x >= "10" && x <= "26")
                dp[i] = dp[i-1] + dp[i-2];
            else dp[i] = dp[i-1];
        }
        return dp[len];
    }
};