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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return result;
        vector<int> v;
        DFS(v, root, sum);
        return result;
    }

    // 由于不全为正数，所以不能提前剪枝
    void DFS(vector<int>& v, TreeNode* root, int cur) {
        cur -= root->val;
        v.push_back(root->val);
        if (!root->left && !root->right) {
            if (!cur) result.push_back(v);
            v.pop_back();
            return ;
        }

        if (root->left) DFS(v, root->left, cur);
        if (root->right) DFS(v, root->right, cur);
        v.pop_back();
    }
};