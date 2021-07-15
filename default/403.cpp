# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    map<int, bool> visited;
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }

    bool dfs(vector<int>& stones, int idx, int jump) {
        int key = idx*2000 + jump;
        if (visited[key] == true) return false;
        else visited[key] = true;

        for (int i = idx+1; i < stones.size(); i++) {
            int dis = stones[i] - stones[idx];
            if (dis > jump+1) break;
            if (dis < jump-1) continue;
            if (stones.size()-1 == i) return true;
            if (dfs(stones, i, dis)) return true;
        }
        return false;
    }
};