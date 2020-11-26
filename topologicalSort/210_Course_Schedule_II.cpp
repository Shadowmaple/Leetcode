# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v;
        int table[numCourses][numCourses];
        int in[numCourses];
        for (int i = 0; i < numCourses; i++) {
            in[i] = 0;
            for (int j = 0; j < numCourses; j++) table[i][j] = 0;
        }

        for (auto p : prerequisites) {
            table[p[1]][p[0]] = 1;
            in[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!in[i]) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            count++;
            v.push_back(idx);
            for (int i = 0; i < numCourses; i++) {
                if (table[idx][i]) {
                    in[i]--;
                    if (!in[i]) q.push(i);
                }
            }
        }
        if (count == numCourses)
            return v;
        return vector<int>{};
    }
};