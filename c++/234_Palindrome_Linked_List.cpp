# include <iostream>
# include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        stack <int>stk;
        ListNode *low = head, *fast = head;
        stk.push(low->val);
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            low = low->next;
            stk.push(low->val);
        }
        if (fast->next == nullptr)
            stk.pop();
        while (low->next) {
            low = low->next;
            if (!stk.empty() && stk.top() != low->val)
                return false;
            stk.pop();
        }
        return true;
    }
};