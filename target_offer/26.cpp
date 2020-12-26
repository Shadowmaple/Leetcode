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

// 先把所有可能是 B 树的根节点找出，再挨个检查
class Solution {
public:
    vector<TreeNode*> v;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;

        findRootNode(A, B->val);
        if (v.empty()) return false;
        // 可能节点值会有多个
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

// 在查找可能是 B 树的时候，就校验
class Solution2 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;

        return check(A, B);
    }

    bool isAbsoluteSub(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;

        if (A->val != B->val) return false;

        return isAbsoluteSub(A->left, B->left) && isAbsoluteSub(A->right, B->right);
    }

    bool check(TreeNode* A, TreeNode* B) {
        if (!A) return false;
        if (A->val == B->val) {
            if (isAbsoluteSub(A, B))
                return true;
        }

        return check(A->left, B) || check(A->right, B);
    }
};