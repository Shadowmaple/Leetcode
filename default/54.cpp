# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row1 = 0, row2 = matrix.size()-1;
        int col1 = 0, col2 = matrix[0].size()-1;
        while (row1 <= row2 && col1 <= col2) {
            for (int i = col1; i <= col2; i++)
                res.push_back(matrix[row1][i]);
            row1++;
            if (row1 > row2) break;
            for (int i = row1; i <= row2; i++)
                res.push_back(matrix[i][col2]);
            col2--;
            if (col1 > col2) break;
            for (int i = col2; i >= col1; i--)
                res.push_back(matrix[row2][i]);
            row2--;
            if (row1 > row2) break;
            for (int i = row2; i >= row1; i--)
                res.push_back(matrix[i][col1]);
            col1++;
        }

        return res;
    }
};