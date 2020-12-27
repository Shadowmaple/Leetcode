# include <iostream>
# include <vector>
# include <string>
# include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            string valStr = cur ? to_string(cur->val) : "null";
            if (s != "[") s += ",";
            s += valStr;

            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() < 3) return nullptr;

        int low = 1, quick = 1;

        TreeNode *root = scan(data, low, quick);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && quick < data.length()-1) {
            auto cur = q.front();
            q.pop();
            cur->left = scan(data, low, quick);
            cur->right = scan(data, low, quick);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        return root;
    }

    TreeNode* scan(string& data, int& low, int& quick) {
        while (quick < data.length()-1) {
            if (data[quick] != ',') {
                quick++;
                continue;
            }
            string s = data.substr(low, quick-low);
            low = ++quick;
            if (s == "null") return nullptr;
            int val = stoi(s);
            return new TreeNode(val);
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));