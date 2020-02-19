# include <iostream>
# include <vector>
using namespace std;

// 数独，要再理一下
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowVisited(9, vector<bool>(9, false));
        vector<vector<bool>> colVisited(9, vector<bool>(9, false));
        vector<vector<bool>> tbVisited(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rowVisited[i][n] = true;
                colVisited[j][n] = true;
                tbVisited[i/3*3+j/3][n] = true;
            }
        }

        backTracking(board, rowVisited, colVisited, tbVisited, 0, 0);
    }

    bool backTracking(vector<vector<char>>& board, vector<vector<bool>>& rowVisited,
            vector<vector<bool>>& colVisited, vector<vector<bool>>& tbVisited, int row, int col) {

        if (col == 9) {
            col = 0;
            row++;
        }
        if (row >= 9) return true;
        if (board[row][col] != '.') {
            if (backTracking(board, rowVisited, colVisited, tbVisited, row, col+1))
                return true;
            return false;
        }

        for (int i = 0; i < 9; i++) {
            if (rowVisited[row][i] || colVisited[col][i] || tbVisited[row/3*3+col/3][i])
                continue;
            rowVisited[row][i] = colVisited[col][i] = tbVisited[row/3*3+col/3][i] = true;
            board[row][col] = i + '1';

            if(backTracking(board, rowVisited, colVisited, tbVisited, row, col+1))
                return true;

            board[row][col] = '.';
            rowVisited[row][i] = colVisited[col][i] = tbVisited[row/3*3+col/3][i] = false;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s.solveSudoku(board);
    return 0;
}