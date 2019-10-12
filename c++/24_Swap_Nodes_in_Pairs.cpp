// 执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
// 内存消耗 :8.7 MB, 在所有 cpp 提交中击败了69.90%的用户
// 第一次自己写的击败100%用户，纪念一下
// 使用三个指针，快慢指针的思路

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode node = ListNode(0);
        ListNode *p1, *p2, *p = &node;
        p->next = head;
        p1 = head;
        p2 = head->next;
        head = p;
        while (p2 != NULL) {
            p1->next = p2->next;
            p2->next = p1;
            p->next = p2;
            swap(p1, p2);

            for (int i=0; i < 2 && p1 != NULL && p2 != NULL && p != NULL; i++) {
                p1 = p1->next;
                p2 = p2->next;
                p = p->next;
            }
        }
        return head->next;
    }
};