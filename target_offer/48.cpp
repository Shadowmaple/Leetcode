# include <iostream>
# include <set>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) return 0;
        int l = 0, r = 0;
        set<char> visited;
        int result = 0;
        while (r < s.length()) {
            if (!visited.count(s[r])) {
                visited.insert(s[r]);
                result = max(result, r-l+1);
            } else {
                while (l < r && s[l] != s[r]) {
                    visited.earse(s[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return result;
    }
};

// 动态规划
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) return 0;
        int dp[s.length()];
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < s.length(); i++) {
            // 查找s[i]左边第一个重复的字符
            // 优化：使用哈希表存储
            int j = i-1;
            while (j >= 0 && s[j] != s[i]) j--;

            // 1.左边无重复字符时，L(n) = L(n-1)+1
            // 2.重复字符在最长区间外，即 L(n-1)<i-j, L(n) = L(n-1)+1
            // 3.重复字符在区间内，即 L(n-1)>=i-j, L(n) = i-j
            // 左边无重复字符时，j<0，即 L(n-1) < i-j 恒成立
            if (dp[i-1] < i - j)
                dp[i] = dp[i-1] + 1;
            else dp[i] = i - j;
            result = max(result, dp[i]);
        }
        return result;
    }
};