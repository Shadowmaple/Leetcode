# include<iostream>
# include<vector>
# include<queue>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if (root) q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            v.push_back(cur->val);
        }
        return v;
    }
};