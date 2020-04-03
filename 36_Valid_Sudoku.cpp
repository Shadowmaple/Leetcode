# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool tbs[9][9] = {false};

        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                if (rows[i][n] || cols[j][n] || tbs[i/3*3+j/3][n])
                    return false;
                rows[i][n] = cols[j][n] = tbs[i/3*3+j/3][n] = true;
            }
        }
        return true;
    }
};