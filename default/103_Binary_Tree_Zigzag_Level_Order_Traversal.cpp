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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<int> v;
        deque<int> dq;
        queue<TreeNode*> q;
        q.push(root);
        bool oddLevel = true;
        TreeNode* cur = nullptr;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                cur = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                q.pop();
                if (oddLevel) dq.push_back(cur->val);
                else dq.push_front(cur->val);
            }
            while (!dq.empty()) {
                v.push_back(dq.front());
                dq.pop_front();
            }
            oddLevel = !oddLevel;
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};