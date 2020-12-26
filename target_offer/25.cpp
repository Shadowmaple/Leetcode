# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 额外开一条链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        auto cur = root;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while (l1) {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2) {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }
        return root->next;
    }
};

// 在原来的一条链表上修改
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* pre = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                pre->next = l2;
                l2 = l2->next;
            } else {
                pre->next = l1;
                l1 = l1->next;
            }
            pre = pre->next;
        }

        while (l1) {
            pre->next = l1;
            l1 = l1->next;
            pre = pre->next;
        }

        while (l2) {
            pre->next = l2;
            l2 = l2->next;
            pre = pre->next;
        }

        return head->next;
    }
};