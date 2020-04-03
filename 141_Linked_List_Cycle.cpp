# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 快慢指针，快指针必定追上慢指针
// 另一种方法：哈希表，记录已经遍历过的节点（用bool等方式表示已到达）
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode *p = head->next;
        while (p && p->next) {
            if (p == head)
                return true;
            p = p->next->next;
            head = head->next;
        }
        return false;
    }
};
