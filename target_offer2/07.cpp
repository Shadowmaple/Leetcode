# include <iostream>
# include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preBegin > preEnd) return nullptr;
        auto root = new TreeNode(preorder[preBegin]);
        int idx = inBegin;
        while (inorder[idx] != preorder[preBegin]) idx++;
        int len = idx - inBegin;
        root->left = build(preorder, inorder, preBegin+1, preBegin+len, inBegin, idx-1);
        root->right = build(preorder, inorder, preBegin+len+1, preEnd, idx+1, inEnd);
        return root;
    }
};