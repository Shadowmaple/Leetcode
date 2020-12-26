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
    vector<TreeNode*> v;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;

        findRootNode(A, B->val);
        if (v.empty()) return false;
        for (auto root : v) {
            if (isAbsoluteSub(root, B))
                return true;
        }
        return false;
    }

    bool isAbsoluteSub(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;

        if (A->val != B->val) return false;

        return isAbsoluteSub(A->left, B->left) && isAbsoluteSub(A->right, B->right);
    }

    void findRootNode(TreeNode* A, int val) {
        if (!A) return ;
        if (A->val == val)
            v.push_back(A);

        findRootNode(A->left, val);
        findRootNode(A->right, val);
    }
};