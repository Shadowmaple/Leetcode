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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;

        ListNode *p1, *p2 = head;
        p1 = new ListNode(0);
        p1->next = head;
        head = p1;
        while (p2) {
            if (p2->val == val) {
                p2 = p2->next;
                continue;
            }
            p1->next = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p2;
        return head->next;
    }
};