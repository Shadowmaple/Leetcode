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
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;

        this->preorder = preorder;
        this->inorder = inorder;

        return build(0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(int preBegin, int preEnd, int inBegin, int inEnd) {
        int rootVal = preorder[preBegin];

        TreeNode* tree = new TreeNode(rootVal);

        if (inBegin == inEnd) return tree;

        int rootIdx = inBegin;
        while (rootIdx <= inEnd && inorder[rootIdx] != rootVal)
            rootIdx++;

        int leftCount = rootIdx - inBegin;
        if (leftCount)
            tree->left = build(preBegin+1, preBegin+leftCount, inBegin, rootIdx-1);
        if (preBegin+leftCount+1 <= preEnd)
            tree->right = build(preBegin+leftCount+1, preEnd, rootIdx+1, inEnd);

        return tree;
    }
};