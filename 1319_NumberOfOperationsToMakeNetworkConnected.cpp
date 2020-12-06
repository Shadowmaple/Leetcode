# include <iostream>
# include <vector>
# include <set>
# include <queue>
# include <map>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 线缆不够
        if (n - 1 > connections.size()) return -1;

        map<int, set<int>> mp;
        int begin = connections[0][0];
        for (auto cn : connections) {
            int a = cn[0], b = cn[1];
            if (a > b) swap(a, b);
            mp[a].insert(b);
            begin = min(begin, a);
        }

        int count = 0;
        set<int> visited;
        queue<int> q;
        q.push(begin);
        visited.insert(begin);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto t : mp[cur]) {
                if (visited.count(t)) count++;
                else {
                    q.push(t);
                    visited.insert(t);
                }
            }
        }
        int remain = n - visited.size();
        return remain < count ? remain : count;
    }
};