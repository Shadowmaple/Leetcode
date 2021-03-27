# include <iostream>
using namepace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head->next || k == 1) return head;
        auto cur = head;
        auto nHead = new ListNode(0, head);
        cur = nHead;
        while (cur->next) {
            auto begin = cur->next;
            auto end = begin;
            int count = k;
            while (count && end) {
                end = end->next;
                count--;
            }
            if (count) break;

            auto temp = reverse(cur->next, k);
            cur->next = temp;
            begin->next = end;
            cur = begin;
        }
        return nHead->next;
    }

    ListNode* reverse(ListNode* head, int k) {
        if (--k == 0) return head;
        auto p = reverse(head->next, k);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
