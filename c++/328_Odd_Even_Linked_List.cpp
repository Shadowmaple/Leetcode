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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next==nullptr)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next, *even_tail = even;
        ListNode *p1 = even->next, *p2 = p1;
        even_tail->next = nullptr;
        while (p2) {
            p1 = p2;
            p2 = p2->next;

            // 奇数序列
            p1->next = even;
            odd->next = p1;
            odd = odd->next;

            if (p2 == nullptr) break;

            p1 = p2;
            p2 = p2->next;

            // 偶数序列
            even_tail->next = p1;
            even_tail = even_tail->next;
            even_tail->next = nullptr;
        }
        return head;
    }
};