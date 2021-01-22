# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!grid[i][j]) continue;
                int num = backTracking(grid, i, j, visited);
                if (result < num) result = num;
            }
        }
        return result;
    }

    int backTracking(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row == grid.size() || col < 0 ||
            col == grid[0].size() || visited[row][col] || !grid[row][col]) {

            return 0;
        }

        int max = 0;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int n;
            switch (i) {
            case 0 : n = backTracking(grid, row+1, col, visited); break;
            case 1 : n = backTracking(grid, row-1, col, visited); break;
            case 2 : n = backTracking(grid, row, col-1, visited); break;
            case 3 : n = backTracking(grid, row, col+1, visited); break;
            }
            if (max < n) max = n;
        }
        visited[row][col] = false;
        return grid[row][col] + max;
    }
};