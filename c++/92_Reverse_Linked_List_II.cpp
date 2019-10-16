# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 方法：迭代，反转，对地址操作
// 这题还可以直接改变链表的值进行反转，一种是用栈，
// 另一种像反转字符串一样，从两头向中间移动，依次交换两者的值
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode *p1, *p2, *p3, *p4;
        p1 = new ListNode(0);
        p1->next = head;
        head = p1;

        int i = 1;
        for (; i < m; i++)
            p1 = p1->next;
        p2 = p1->next;
        p4 = p3 = p2->next;

        for (; i < n; i++) {
            p4 = p4->next;
            p3->next = p2;
            p2 = p3;
            p3 = p4;
        }
        p1->next->next = p3;
        p1->next = p2;

        return head->next;
    }
};