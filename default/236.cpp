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
    int p, q;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p->val;
        this->q = q->val;
        return search(root);
    }

    TreeNode* search(TreeNode* root) {
        if (!root) return nullptr;
        if (root->val == p || root->val == q) return root;
        auto left = search(root->left);
        auto right = search(root->right);
        if (left && right) return root;
        if (left) return left;
        if (right) return right;
        return nullptr;
    }
};
