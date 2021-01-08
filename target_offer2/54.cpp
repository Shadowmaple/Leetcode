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
    int res;
    int kthLargest(TreeNode* root, int k) {
        search(root, k);
        return res;
    }

    bool search(TreeNode* root, int& k) {
        if (!root) return false;
        bool flag = search(root->right, k);
        if (flag) return true;
        if (--k == 0) {
            res = root->val;
            return true;
        }
        return search(root->left, k);
    }
};