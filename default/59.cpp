# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        auto res = vector<vector<int>>(n, vector<int>(n, 1));
        int cur = 1;
        int row1 = 0, row2 = n-1, col1 = 0, col2 = n-1;
        while (row1 <= row2 || col1 <= col2) {
            for (int i = col1; i <= col2; i++)
                res[row1][i] = cur++;
            row1++;
            for (int i = row1; i <= row2; i++)
                res[i][col2] = cur++;
            col2--;
            for (int i = col2; i >= col1; i--)
                res[row2][i] = cur++;
            row2--;
            for (int i = row2; i >= row1; i--)
                res[i][col1] = cur++;
            col1++;
        }

        return res;
    }
};