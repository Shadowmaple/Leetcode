# include <iostream>
# include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return ;
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!i && !j) dp[i][j] = matrix[i][j];
                else if (!i) dp[i][j] = matrix[i][j] + dp[i][j-1];
                else if (!j) dp[i][j] = matrix[i][j] + dp[i-1][j];
                else dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = dp[row2][col2];

        if (!row1 && !col1) return sum;
        else if (!row1) sum -= dp[row2][col1-1];
        else if (!col1) sum -= dp[row1-1][col2];
        else sum += dp[row1-1][col1-1] - dp[row2][col1-1] - dp[row1-1][col2];

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */