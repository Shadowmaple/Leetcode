# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 最无语的题
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node->next;
        node->val = p->val;
        node->next = p->next;
        delete p;
    }
};