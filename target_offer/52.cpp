# include <iostream>
# include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 栈
// 从链表尾部开始回返，遇到相交时返回
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        stack<ListNode*> sk1, sk2;
        auto cur = headA;
        while (cur) {
            sk1.push(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            sk2.push(cur);
            cur = cur->next;
        }
        ListNode *pre = nullptr;
        while (!sk1.empty() && !sk2.empty()) {
            if (sk1.top() != sk2.top())
                break;
            pre = sk1.top();
            sk1.pop();
            sk2.pop();
        }
        return pre;
    }
};

// 最浪漫的解法/思想
// “我走你的路，你走我的路，然后我们相遇了”
// 描述：
// 链表A走到尾部时变到链表B首部，链表B走到尾部时变到链表A首部
// 两者同时遍历，直到相遇，该节点就是第一个公共节点
// 链表A长度为 L1+C，链表B长度为 L2+C
// 那么 L1+L2+C = L1+L2+C
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        auto l1 = headA, l2 = headB;
        while (l1 != l2) {
            l1 = l1 != nullptr ? l1->next : headB;
            l2 = l2 != nullptr ? l2->next : headA;
        }

        return l1;
    }
};