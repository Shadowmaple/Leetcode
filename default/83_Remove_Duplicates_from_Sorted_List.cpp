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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;

        while (p2) {
            while (p2 && p1->val == p2->val)
                p2 = p2->next;
            p1->next = p2;
            p1 = p1->next;
        }
        return head;
    }
};