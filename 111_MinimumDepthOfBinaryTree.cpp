# include <iostream>
# include <queue>
# include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            depth++;
            while (size--) {
                auto t = q.front();
                q.pop();
                if (!t->left && !t->right) return depth;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return depth;
    }
};