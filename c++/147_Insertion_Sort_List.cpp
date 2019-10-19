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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p1 = head, *p2 = head;
        ListNode *p = new ListNode(0);
        head = p;
        while (p1) {
            p = head;
            while (p->next && p1->val > p->next->val)
                p = p->next;

            p2 = p2->next;
            p1->next = p->next;
            p->next = p1;
            p1 = p2;
        }
        return head->next;
    }
};