# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if (root == nullptr) return v;

        queue<TreeNode*> q;
        vector<int> sv;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> sq;
            while (!q.empty()) {
                TreeNode* t = q.front();
                q.pop();
                sv.push_back(t->val);
                if (t->left) sq.push(t->left);
                if (t->right) sq.push(t->right);
            }
            v.push_back(sv);
            sv.clear();
            q = sq;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};