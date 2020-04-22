# include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int net[n][m];
        net[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j)
                    net[i][j] = net[i-1][j] + net[i][j-1];
                else if (i)
                    net[i][j] = net[i-1][j];
                else if (j)
                    net[i][j] = net[i][j-1];
            }
        }
        return net[n-1][m-1];
    }
};