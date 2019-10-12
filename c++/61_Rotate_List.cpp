# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 每次向右移动一位，移动k次
// 81.95%时间用户，75.89空间用户
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *p = head;
        // k很大的情况
        int count = 0;
        while (p != NULL ) {
            p = p->next;
            count++;
        }
        k %= count;

        for (int i=0; i < k; i++) {
            p = head;
            while (p->next != NULL && p->next->next != NULL)
                p = p->next;
            p->next->next = head;
            head = p->next;
            p->next = NULL;
        }

        return head;
    }
};
