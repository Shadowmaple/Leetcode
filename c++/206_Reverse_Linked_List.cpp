# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 递归，很巧妙的连接方式
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL ||head->next == NULL)
            return head;

        ListNode *p = reverseList(head->next);
        // 以下两句划重点，很巧妙
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};