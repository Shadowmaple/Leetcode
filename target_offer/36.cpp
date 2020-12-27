# include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 中序遍历，具体的细节琢磨了蛮久，最终还是靠自己解出来了，挺开心的
class Solution {
public:
    Node* pre;
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node *head = new Node(0);
        Node *begin = root, *end = root;
        while (begin->left) begin = begin->left;
        while (end->right) end = end->right;

        pre = head;
        InOrder(root);
        begin->left = end;
        end->right = begin;

        return head->right;
    }

    void InOrder(Node* root) {
        if (!root) return ;

        InOrder(root->left);
        pre->right = root;
        root->left = pre;
        pre = root;
        InOrder(root->right);
    }
};