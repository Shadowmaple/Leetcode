# include <iostream>
# include <stack>
# include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> sk;
        while (head) {
            sk.push(head->val);
            head = head->next;
        }
        vector<int> v;
        while (!sk.empty()) {
            v.push_back(sk.top());
            sk.pop();
        }
        return v;
    }
};

// 递归
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        dfs(head, v);
        return v;
    }

    void dfs(ListNode* head, vector<int>& v) {
        if (head == nullptr) return ;
        dfs(head->next, v);
        v.push_back(head->val);
    }
};