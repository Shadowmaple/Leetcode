# include <iostream>
# include <vector>
# include <set>
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i < board.size(); i++) {
            for (int j=0; j < board[i].size(); j++) {
                if (DFS(0, i, j)) return true;;
            }
        }
        return false;
    }

    bool DFS(int idx, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        if (word[idx] != board[i][j]) return false;
        if (visited[i][j]) return false;
        if (++idx >= word.length()) return true;
        visited[i][j] = true;

        auto x = DFS(idx, i-1, j) || DFS(idx, i+1, j) ||
            DFS(idx, i, j-1) || DFS(idx, i, j+1);

        visited[i][j] = false;
        return x;
    }
};