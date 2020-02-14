# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int num = 0;
        vector<bool> visited(tiles.length(), false);
        sort(tiles.begin(), tiles.end());
        DFS(tiles, num, visited);
        return num;
    }

    void DFS(string& tiles, int& num, vector<bool>& visited) {
        for (int i = 0; i < tiles.length(); i++) {
            if (visited[i]) continue;
            // 剪枝
            if (i > 0 && tiles[i] == tiles[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            num++;
            DFS(tiles, num, visited);
            visited[i] = false;
        }
    }
};