# include <iostream>
# include <vector>
# include <queue>
# include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 辅助栈
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        vector<int> v;
        queue<TreeNode*> q;
        stack<int> sk;
        q.push(root);
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            TreeNode* cur;
            while (size--) {
                cur = q.front();
                q.pop();
                if (step & 1) v.push_back(cur->val);
                else sk.push(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            while (!sk.empty()) {
                v.push_back(sk.top());
                sk.pop();
            }
            res.push_back(v);
            v.clear();
            step++;
        }
        return res;
    }
};

// vector 翻转
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> v;

        queue<TreeNode*> q;
        q.push(root);
        bool left = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            // 翻转，其实新建了一个从右往左的 vector，这样比调用 reserve 效率高
            if (!left) res.push_back(vector<int>(v.rbegin(), v.rend()));
            else res.push_back(v);
            v.clear();
            left = !left;
        }
        return res;
    }
};