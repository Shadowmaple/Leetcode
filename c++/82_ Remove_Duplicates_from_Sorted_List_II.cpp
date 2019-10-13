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
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p1, *p2;
        p2 = head->next;
        p1 = new ListNode(-1);
        p1->next = head;
        head = p1;

        while (p2 != NULL) {
            while (p2 && p1->next->val == p2->val) {
                p2 = p2->next;
            }
            if (p1->next->next != p2)
                p1->next = p2;
            else
                p1 = p1->next;
        }

        return head->next;
    }
};
