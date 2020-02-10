# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int rowLen, colLen;
    bool exist(vector<vector<char>>& board, string word) {
        rowLen = board.size();
        colLen = board[0].size();
        vector<vector<bool>> used(rowLen, vector<bool>(colLen, false));
        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                if (DFS(board, word, used, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>>& board, string& word, vector<vector<bool>>& used, int row, int col, int w) {
        // 越界
        if (row < 0 || row >= rowLen || col < 0 || col >= colLen)
            return false;

        if (used[row][col] || board[row][col] != word[w])
            return false;

        if (w == word.length()-1)
            return true;

        used[row][col] = true;

        if (DFS(board, word, used, row, col+1, w+1) ||
            DFS(board, word, used, row, col-1, w+1) ||
            DFS(board, word, used, row+1, col, w+1) ||
            DFS(board, word, used, row-1, col, w+1))
            return true;

        used[row][col] = false;

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << s.exist(board, "SEE") << endl;
}