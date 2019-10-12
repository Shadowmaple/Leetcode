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
    // 快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2;
        p1 = p2 = head;
        for (int i = 0; i < n; i++)
            p1 = p1->next;

        // 删除的是头结点情况
        if (!p1)
            return head->next;

        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;

        return head;
    }
};