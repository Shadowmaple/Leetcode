# include <iostream>
# include <vector>
# include <map>
using namespace std;

// DFS+记忆化
class Solution {
public:
    int m, n;
    map<int, int> mp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        return dfs(dungeon, 0, 0);
    }

    int dfs(vector<vector<int>>& dungeon, int row, int col) {
        int key = row * n + col;
        if (mp[key] != 0) return mp[key];

        int res;
        if (row == m-1 && col == n-1) {
            res = max(1-dungeon[row][col], 1);
        } else if (row == m-1) {
            res = max(dfs(dungeon, row, col+1)-dungeon[row][col], 1);
        } else if (col == n-1) {
            res = max(dfs(dungeon, row+1, col)-dungeon[row][col], 1);
        } else
            res = max(min(dfs(dungeon, row+1, col), dfs(dungeon, row, col+1))-dungeon[row][col], 1);

        mp[key] = res;
        return res;
    }
};

// DP
class Solution2 {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m][n];
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    dp[i][j] = max(1-dungeon[i][j], 1);
                    continue;
                }
                if (i == m-1) dp[i][j] = max(dp[i][j+1]-dungeon[i][j], 1);
                else if (j == n-1) dp[i][j] = max(dp[i+1][j]-dungeon[i][j], 1);
                else dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};