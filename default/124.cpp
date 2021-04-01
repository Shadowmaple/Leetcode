# include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    int res;
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        res = root->val;
        int cur = search(root);
        return max(res, cur);
    }

    int search(TreeNode* root) {
        if (!root) return 0;
        int l = search(root->left);
        int r = search(root->right);
        res = max(res, l+r+root->val); // 经过根节点，左右两树的
        int x = root->val + max(0, max(l, r)); // 以该根节点为终点的路径
        res = max(res, x);
        return x;
    }
};