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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a->next;
            b = b->next;
            if (!a && !b) return nullptr;
            if (!a) a = headB;
            if (!b) b = headA;
        }
        return a;
    }
};