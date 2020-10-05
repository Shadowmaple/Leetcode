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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            bool flag = false;
            int len = q.size();
            for (int i = 0 ; i < len; i++) {
                auto t = q.front();
                if (t != nullptr) {
                    q.push(t->left);
                    q.push(t->right);
                    flag = true;
                } else {
                    q.push(nullptr);
                    q.push(nullptr);
                }

                q.pop();
                v.push_back(t);
            }
            if (!flag) break;
            for (int i=0, j=v.size()-1; i < j; i++, j--) {
                if (v[i] == nullptr && v[j] == nullptr) continue;
                if (v[i] == nullptr || v[j] == nullptr) return false;
                if (v[i]->val != v[j]->val) return false;
            }
            v.clear();
        }

        return true;
    }
};

// 递归
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};