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
    int sumOfLeftLeaves(TreeNode* root) {
        return order(root, false);
    }

    int order(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right)
            return left ? root->val : 0;
        return order(root->left, true) + order(root->right, false);
    }
};
