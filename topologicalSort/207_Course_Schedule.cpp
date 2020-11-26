# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建邻接表和入度
        int v[numCourses][numCourses];
        int in[numCourses];
        for (int i = 0; i < numCourses; i++) {
            in[i] = 0;
            for (int j = 0; j < numCourses; j++) v[i][j] = 0;
        }

        // 邻接表和入度初始化
        for (auto prerequisite : prerequisites) {
            v[prerequisite[1]][prerequisite[0]]++;
            in[prerequisite[0]]++;
        }

        // 入度为 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!in[i]) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            count++;
            for (int i = 0; i < numCourses; i++) {
                if (v[idx][i]) {
                    in[i]--;
                    if (!in[i]) q.push(i);
                }
            }
        }
        return count == numCourses;
    }
};