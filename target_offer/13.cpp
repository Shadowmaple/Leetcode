# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int m, n, k;
    vector<vector<bool>> visited;
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));

        return DFS(0, 0);
    }

    int DFS(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (visited[i][j]) return 0;
        if (!checkNumPath(i, j)) return 0;
        visited[i][j] = true;

        return 1 + DFS(i+1, j) + DFS(i, j+1);
    }

    bool checkNumPath(int i, int j) {
        int num = 0;
        while (i) {
            num += i % 10;
            i /= 10;
        }
        while (j) {
            num += j % 10;
            j /= 10;
        }
        return num <= k;
    }
};