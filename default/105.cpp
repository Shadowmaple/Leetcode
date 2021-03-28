# include <iostream>
# include <vector>
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
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return binary(0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* binary(int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preBegin > preEnd) return nullptr;
        if (preBegin == preEnd) return new TreeNode(preorder[preBegin]);
        auto root = new TreeNode(preorder[preBegin]);
        int idx = inBegin;
        while (idx < inEnd && inorder[idx] != root->val)
            idx++;
        int len = idx - inBegin;
        root->left = binary(preBegin+1, preBegin+len, inBegin, idx-1);
        root->right = binary(preBegin+len+1, preEnd, idx+1, inEnd);
        return root;
    }
};
