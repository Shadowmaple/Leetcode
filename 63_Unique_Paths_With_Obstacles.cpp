# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long net[m][n];
        net[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    net[i][j] = 0;
                    continue;
                }
                if (i && j)
                    net[i][j] = net[i-1][j] + net[i][j-1];
                else if (i)
                    net[i][j] = net[i-1][j];
                else if (j)
                    net[i][j] = net[i][j-1];
            }
        }
        return net[m-1][n-1];
    }
};