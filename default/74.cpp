# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int a = 0, b = col-1;
        while (a < row && a >= 0 && b < col && b >= 0) {
            if (matrix[a][b] == target) return true;
            if (matrix[a][b] > target) b--;
            else a++;
        }
        return false;
    }
};
