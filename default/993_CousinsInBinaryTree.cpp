# include <iostream>
# include <queue>
# include <map>
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        map<int, int> mp;
        while (!q.empty()) {
            int size = q.size();
            int parent = 0;
            while (size--) {
                auto cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                    mp[cur->left->val] = cur->val;
                }
                if (cur->right) {
                    q.push(cur->right);
                    mp[cur->right->val] = cur->val;
                }

                if (cur->val != x && cur->val != y)
                    continue;

                if (parent == 0) parent = mp[cur->val];
                else if (parent == mp[cur->val]) return false;
                else return true;
            }
            if (parent != 0) return false;
        }
        return false;
    }
};