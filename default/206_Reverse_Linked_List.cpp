# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归，很巧妙的连接方式
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = reverseList(head->next);
        // 以下两句划重点，很巧妙
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

// 递归
class Solution2 {
public:
    ListNode* newHead;
    ListNode* reverseList(ListNode* head) {
        auto cur = reverse(head);
        cur->next = nullptr;
        return newHead->next;
    }

    ListNode* reverse(ListNode* head) {
        if (!head) {
            newHead = new ListNode();
            return newHead;
        }
        auto cur = reverse(head->next);
        cur->next = head;
        return head;
    }
};

// 迭代
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        auto newHead = new ListNode();
        auto cur = head;
        newHead->next = cur;
        while (cur->next) {
            auto temp = cur->next->next;
            cur->next->next = newHead->next;
            newHead->next = cur->next;
            cur->next = temp;
        }
        return newHead->next;
    }
};