# include <iostream>
# include <queue>
# include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        vector<int> v;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            result.push_back(v);
            v.clear();
        }

        return result;
    }
};