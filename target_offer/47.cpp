# include <iostream>
# include <vector>
using namespace std;

// DFS 超时
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        return DFS(grid, 0, 0);
    }

    int DFS(vector<vector<int>>& grid, int row, int col) {
        if (row > grid.size()-1 || col > grid[0].size()-1)
            return 0;

        return grid[row][col] + max(DFS(grid, row+1, col), DFS(grid, row, col+1));
    }
};

// 动态规划
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dp[row][col];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!i && !j) continue;
                if (!i) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if (!j) dp[i][j] = grid[i][j] + dp[i-1][j];
                else dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};