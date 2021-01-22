# include<iostream>
# include<vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        v.push_back(root->val);
        vector<int> l = preorderTraversal(root->left);
        vector<int> r = preorderTraversal(root->right);
        for (int i = 0; i < l.size(); i++) v.push_back(l.at(i));
        for (int i = 0; i < r.size(); i++) v.push_back(r.at(i));
        return v;
    }
};