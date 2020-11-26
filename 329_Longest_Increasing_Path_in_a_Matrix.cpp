# include <iostream>
# include <vector>
# include <queue>
# include <map>
# include <set>
using namespace std;

// DFS + 备忘录，不加备忘录会超时
class Solution {
public:
    vector<vector<int>> cp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        cp = *(new vector<vector<int>>(m, vector<int>(n)));

        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = DFS(matrix, i, j, matrix[i][j]-1);
                num = max(count, num);
            }
        }
        return num;
    }

    int DFS(vector<vector<int>>& matrix, int x, int y, int pre) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return 0;

        if (pre >= matrix[x][y]) return 0;

        if (cp[x][y]) return cp[x][y];

        // 向上、向下、向左、向右
        cp[x][y] = 1 + max(
                        max(DFS(matrix, x-1, y, matrix[x][y]), DFS(matrix, x+1, y, matrix[x][y])),
                        max(DFS(matrix, x, y-1, matrix[x][y]), DFS(matrix, x, y+1, matrix[x][y]))
                    );
        return cp[x][y];
    }
};