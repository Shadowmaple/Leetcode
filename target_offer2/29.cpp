# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size() || !matrix[0].size()) return res;

        int row_low = 0, row_high = matrix.size()-1;
        int col_low = 0, col_high = matrix[0].size()-1;
        int a = 0, b = 0;
        while (b <= col_high) {
            while (b <= col_high) {
                res.push_back(matrix[a][b]);
                b++;
            }
            row_low++;
            a++;
            b--;
            if (a > row_high) break;
            while (a <= row_high) {
                res.push_back(matrix[a][b]);
                a++;
            }
            col_high--;
            b--;
            a--;
            if (b < col_low) break;
            while (b >= col_low) {
                res.push_back(matrix[a][b]);
                b--;
            }
            row_high--;
            a--;
            b++;
            if (a < row_low) break;
            while (a >= row_low) {
                res.push_back(matrix[a][b]);
                a--;
            }
            col_low++;
            b++;
            a++;
        }
        return res;
    }
};