# include <iostream>
# include <string>
using namespace std;

// DFS
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        return DFS(s, 0);
    }

    int DFS(string& s, int idx) {
        if (idx >= s.length()) return 1;

        int num = DFS(s, idx+1);
        if (s[idx] != '0' && idx < s.length()-1 && stoi(s.substr(idx, 2)) < 26)
            num += DFS(s, idx+2);
        return num;
    }
};

// 动态规划
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int dp[s.length()+1];
        dp[0] = dp[1] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) < 26)
                dp[i+1] = dp[i] + dp[i-1];
            else dp[i+1] = dp[i];
        }
        return dp[s.length()];
    }
};