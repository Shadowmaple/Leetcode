# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int blank = 0, origin[2];
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!grid[i][j]) blank++;
                else if (grid[i][j] == 1) {
                    origin[0] = i; origin[1] = j;
                }
            }
        }
        return DFS(grid, visited, origin[0], origin[1], blank);
    }

    int DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int& blank) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || visited[row][col])
            return 0;

        if (grid[row][col] == -1) return 0;
        else if (grid[row][col] == 2) return (blank == -1)? 1 : 0;

        visited[row][col] = true;
        blank--;
        int count = 0;
        count += DFS(grid, visited, row+1, col, blank);
        count += DFS(grid, visited, row-1, col, blank);
        count += DFS(grid, visited, row, col-1, blank);
        count += DFS(grid, visited, row, col+1, blank);
        blank++;
        visited[row][col] = false;
        return count;
    }
};