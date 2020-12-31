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
    bool isBalanced(TreeNode* root) {
        int depth = getDepth(root);
        return depth != -1;
    }

    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int x = getDepth(root->left);
        if (x == -1) return -1;
        int y = getDepth(root->right);
        if (y == -1) return -1;
        if (abs(x-y) > 1) return -1;
        return max(x, y) + 1;
    }
};
