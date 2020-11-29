# include <iostream>
# include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* cur = root;
        Node* pre = nullptr;
        int curLevelNum = 1, nextLevelNum = 0;

        if (cur != nullptr) q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (!curLevelNum) {
                pre->next = nullptr;
                curLevelNum = nextLevelNum;
                nextLevelNum = 0;
            } else if (pre) {
                pre->next = cur;
            }

            if (cur->left) {
                q.push(cur->left);
                nextLevelNum++;
            }
            if (cur->right) {
                q.push(cur->right);
                nextLevelNum++;
            }

            curLevelNum--;
            pre = cur;
        }
        return root;
    }
};