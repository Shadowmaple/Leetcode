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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int total = 0;
        auto cur = head;
        while (cur) {
            total++;
            cur = cur->next;
        }
        total -= k;
        cur = head;
        while (total--) {
            cur = cur->next;
        }
        return cur;
    }
};

// double pointers
class Solution2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* low = head;
        ListNode* quick = head;
        // quick 先走 k-1 步
        while (quick) {
            quick = quick->next;
            if (k-- < 1) low = low->next;
        }
        return low;
    }
};