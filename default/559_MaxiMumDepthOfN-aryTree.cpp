# include <iostream>
# include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        int depth = 0;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            depth++;
            while (size--) {
                auto cur = q.front();
                q.pop();
                for (auto n : cur->children) {
                    q.push(n);
                }
            }
        }
        return depth;
    }
};