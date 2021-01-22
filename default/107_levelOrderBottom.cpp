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
            int size = q.size();
            for (int i=0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                sv.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            v.push_back(sv);
            sv.clear();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};