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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p1, *p2;
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p1 = p;
        p2 = head->next;

        while (p2) {
            if (p2->val >= x) {
                p2 = p2->next;
                p1 = p1->next;
                continue;
            }
            if (p->next == p2) {
                p = p->next;
                p2 = p2->next;
                p1 = p1->next;
                continue;
            }
            p1->next = p2->next;
            p2->next = p->next;
            p->next = p2;
            p2 = p1->next;
            p = p->next;
        }
        return head->next;
    }
};