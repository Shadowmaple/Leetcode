# include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p->val, q->val);
    }

    TreeNode* DFS(TreeNode* root, int p, int q) {
        if (!root) return nullptr;
        if (root->val == p || root->val == q)
            return root;
        auto left = DFS(root->left, p, q);
        auto right = DFS(root->right, p, q);
        if (left && right) return root;
        if (left) return left;
        if (right) return right;
        return nullptr;
    }
};