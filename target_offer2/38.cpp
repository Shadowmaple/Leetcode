# include <iostream>
# include <vector>
# include <set>
using namespace std;

class Solution {
public:
    set<string> exist;
    vector<bool> visited;
    vector<string> permutation(string s) {
        vector<string> res;
        visited = vector<bool>(s.length(), false);
        string cur;
        DFS(res, s, cur);
        return res;
    }

    void DFS(vector<string>& res, string& s, string& cur) {
        if (cur.length() == s.length()) {
            if (exist.count(cur)) return ;
            exist.insert(cur);
            res.push_back(cur);
            return ;
        }
        for (int i = 0; i < s.length(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            cur += s[i];
            DFS(res, s, cur);
            cur.pop_back();
            visited[i] = false;
        }
    }
};