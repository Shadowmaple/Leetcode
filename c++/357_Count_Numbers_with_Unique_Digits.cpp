# include <iostream>
# include <vector>
using namespace std;

// 回溯，深度优先搜索
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1; //开始的0
        vector<bool> visited(10, false);
        DFS(count, n, 0, visited);
        return count;
    }

    void DFS(int& count, int& n, int idx, vector<bool>& visited) {
        if (idx == n)
            return ;

        for (int i = 0; i <= 9; i++) {
            if (!idx && !i || visited[i]) continue;
            visited[i] = true;
            count++;
            DFS(count, n, idx+1, visited);
            visited[i] = false;
        }
    }
};