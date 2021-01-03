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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode *n = new ListNode(0);
        n->next = head;
        head = n;
        ListNode *cur = head, *part = head;
        while (part->next && part->next->val < x)
            part = part->next;
        cur = part;
        while (cur && cur->next) {
            if (cur->next->val >= x) {
                cur = cur->next;
                continue;
            }
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = part->next;
            part->next = temp;
            part = part->next;
        }

        return head->next;
    }
};