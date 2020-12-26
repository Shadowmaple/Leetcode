# include <iostream>
# include <vector>
using namespace std;

// 不断压缩边界，想法很妙，这样就不用考虑重复访问的情况了
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (!matrix.size() || !matrix[0].size()) return v;

        int row_begin = 0, row_end = matrix.size()-1;
        int col_begin = 0, col_end = matrix[0].size()-1;
        while (1) {
            for (int i = col_begin; i <= col_end; i++)
                v.push_back(matrix[row_begin][i]);
            row_begin++;
            if (row_begin > row_end) break;
            for (int i = row_begin; i <= row_end; i++)
                v.push_back(matrix[i][col_end]);
            col_end--;
            if (col_begin > col_end) break;
            for (int i = col_end; i >= col_begin; i--)
                v.push_back(matrix[row_end][i]);
            row_end--;
            if (row_begin > row_end) break;
            for (int i = row_end; i >= row_begin; i--)
                v.push_back(matrix[i][col_begin]);
            col_begin++;
            if (col_begin > col_end) break;
        }
        return v;
    }
};

int main() {
    auto matrix = vector<vector<int>>{
        {1,2,3}, {4,5,6}, {7,8,9},
    };
    Solution s;
    auto v = s.spiralOrder(matrix);
    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}