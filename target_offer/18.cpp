# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;

        ListNode* cur = head;
        while (cur->next && cur->next->val != val)
            cur = cur->next;
        cur->next = cur->next->next;
        return head;
    }
};