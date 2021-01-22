# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 采用142环形链表II类似的方法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;

        // 构建环形链表
        ListNode *fast = headA, *slow = headA, *tail = headA;
        while (tail->next)
            tail = tail->next;
        tail->next = headB;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast != slow) {
            tail->next = NULL;
            return NULL;
        }
        fast = headA;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        tail->next = NULL;
        return fast;
    }
};