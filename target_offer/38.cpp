# include <iostream>
# include <vector>
# include <set>
using namespace std;

class Solution {
public:
    vector<string> v;
    vector<string> permutation(string s) {
        DFS(s, 0);
        return v;
    }

    void DFS(string& s, int idx) {
        if (idx >= s.length()) {
            v.push_back(s);
            return ;
        }

        set<char> visited;
        for (int i=idx; i < s.length(); i++) {
            if (visited.count(s[i])) continue;
            visited.insert(s[i]);

            swap(s[idx], s[i]);
            DFS(s, idx+1);
            swap(s[idx], s[i]);
        }
    }
};