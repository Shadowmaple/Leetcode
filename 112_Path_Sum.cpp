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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;

        int cur = sum - root->val;
        if (root->left == nullptr && root->right == nullptr)
            return cur == 0;
        return hasPathSum(root->left, cur) || hasPathSum(root->right, cur);
    }
};