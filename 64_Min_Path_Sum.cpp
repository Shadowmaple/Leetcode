# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int net[m][n];
        net[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i && j)
                    net[i][j] = min(net[i-1][j], net[i][j-1]) + grid[i][j];
                else if (i)
                    net[i][j] = net[i-1][j] + grid[i][j];
                else if (j)
                    net[i][j] = net[i][j-1] + grid[i][j];
            }
        }
        return net[m-1][n-1];
    }
};