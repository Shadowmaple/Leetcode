# include <iostream>
# include <vector>
# include <set>
using namespace std;

// 并查集
class Solution {
public:
    int *parent;
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 线缆不够
        if (n - 1 > connections.size()) return -1;

        int parent[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        this->parent = parent;

        for (auto cn : connections) {
            int a = cn[0], b = cn[1];
            int rootA = find(a), rootB = find(b);
            if (rootA != rootB) {
                parent[rootB] = rootA;
            }
        }

        set<int> st;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            st.insert(root);
        }
        return st.size()-1;
    }

    int find(int p) {
        if (p != parent[p]) return find(parent[p]);
        return p;
    }
};