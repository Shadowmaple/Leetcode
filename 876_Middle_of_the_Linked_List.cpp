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
    ListNode* middleNode(ListNode* head) {
        ListNode *low = head, *fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            low = low->next;
        }
        return low;
    }
};