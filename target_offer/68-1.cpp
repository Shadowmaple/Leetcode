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
        if (p->val > q->val) swap(p, q);
        return DFS(root, p->val, q->val);
    }

    TreeNode* DFS(TreeNode* root, int p, int q) {
        if (!root) return nullptr;

        // 位于右子树
        if (root->val < p) return DFS(root->right, p, q);
        // 位于左子树
        else if (root->val > q) return DFS(root->left, p, q);

        // 分布于左右两侧或一者为根节点
        return root;
    }
};