# include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历（变种），右中左
class Solution {
public:
    int res;
    int kthLargest(TreeNode* root, int k) {
        inOrder(root, k);
        return res;
    }

    bool inOrder(TreeNode* root, int& k) {
        if (!root) return false;

        if(inOrder(root->right, k)) return true;;

        if (--k == 0) {
            res = root->val;
            return true;
        }

        if (inOrder(root->left, k)) return true;
        return false;
    }
};