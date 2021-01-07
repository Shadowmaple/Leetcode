# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DFS(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (idx == word.length()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        if (visited[row][col]) return false;
        if (word[idx] != board[row][col]) return false;

        visited[row][col] = true;
        bool exist = DFS(board, word, idx+1, row-1, col) ||
            DFS(board, word, idx+1, row+1, col) ||
            DFS(board, word, idx+1, row, col-1) ||
            DFS(board, word, idx+1, row, col+1);
        visited[row][col] = false;
        return exist;
    }
};