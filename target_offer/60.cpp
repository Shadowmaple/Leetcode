# include <iostream>
# include <vector>
# include <math.h>
# include <map>
using namespace std;

// 回溯DFS，超时
class Solution {
public:
    vector<double> dicesProbability(int n) {
        map<int, int> mp;

        DFS(mp, n, 0, 0);

        double base = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6*n; i++) {
            double num = mp[i] / base;
            res.push_back(num);
        }

        return res;
    }

    void DFS(map<int,int>& mp, int n, int idx, int sum) {
        if (idx == n) {
            mp[sum]++;
            return ;
        }
        for (int i = 1; i <= 6; i++) {
            DFS(mp, n, idx+1, sum+i);
        }
    }
};

// 递归，超时
// 记忆花，超时
class Solution2 {
public:
    vector<vector<int>> v;
    vector<double> dicesProbability(int n) {
        v = vector<vector<int>>(n+1, vector<int>(6*n+1));

        double base = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6*n; i++) {
            int count = getCount(n, i);
            res.push_back(count / base);
        }

        return res;
    }

    int getCount(int n, int s) {
        if (n == 1)
            return s >= 1 && s <= 6 ? 1 : 0;

        int sum = 0;
        for (int i = max(s-6, 1); i <= s-1; i++) {
            int x = v[n-1][i];
            if (!x) {
                x = getCount(n-1, i);
                v[n-1][i] = x;
            }
            sum += x;
        }
        return sum;
    }
};

// 动态规划
class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[n+1][6*n+1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 6*n; j++)
                dp[i][j] = 0;

        for (int i = 1; i <= 6; i++) dp[1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int s = i; s <= 6*n; s++) {
                dp[i][s] = 0;
                for (int j = 1; j <= 6; j++) {
                    if (s <= j) break;
                    cout << i-1 << ' ' << s-j << " " << dp[i-1][s-j] << endl;
                    dp[i][s] += dp[i-1][s-j];
                }
            }
        }
        for (int s = n; s <= 6*n; s++) {
            cout << dp[n][s] << " ";
        }
        double base = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6*n; i++) {
            res.push_back(dp[n][i] / base);
        }

        return res;
    }
};
