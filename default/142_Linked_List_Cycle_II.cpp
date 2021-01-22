# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 快慢指针，用数学方法推导解决，数学思维能力有待提高
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return head;

        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
