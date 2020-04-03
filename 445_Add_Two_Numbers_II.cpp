# include <iostream>
# include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 两个栈，创建新链表
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sk1, sk2;
        while (l1) {
            sk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            sk2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = new ListNode(0);
        int num = 0;
        while (!sk1.empty() || !sk2.empty() || num / 10) {
            num = num / 10;
            if (!sk1.empty()) {
                num += sk1.top();
                sk1.pop();
            }
            if (!sk2.empty()) {
                num += sk2.top();
                sk2.pop();
            }
            ListNode *n = new ListNode(num % 10);
            n->next = head->next;
            head->next = n;
        }
        return head->next;
    }
};