# include <iostream>
# include <queue>
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool odd = false;
        while (!q.empty()) {
            int size = q.size();
            int val = 0;
            while (size--) {
                auto cur = q.front();
                q.pop();
                if (odd && cur->val&1 || !odd && !(cur->val&1)) return false;
                if (val && (odd && cur->val >= val || !odd && cur->val <= val)) return false;
                val = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            odd = !odd;
        }
        return true;
    }
};