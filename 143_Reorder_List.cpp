# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 快慢指针分为两段，后一段反转，再合并
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return ;

        // 快慢指针分隔两段
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;

        // 后一段反转
        ListNode *p1, *p2;
        p2 = p1 = fast->next;
        fast->next = NULL;
        while (p2) {
            p2 = p2->next;
            p1->next = fast;
            fast = p1;
            p1 = p2;
        }

        // 两段合并
        slow = head;
        while (fast) {
            p1 = slow->next;
            p2 = fast->next;
            slow->next = fast;
            fast->next = p1;
            slow = p1;
            fast = p2;
        }
    }
};