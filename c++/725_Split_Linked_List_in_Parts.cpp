# include <iostream>
# include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // 获取长度
        int len = 0;
        ListNode *p = root;
        while (p) {
            len++;
            p = p->next;
        }

        // 计算每段长度
        int *num = new int[k]{};
        if (len <= k) {
            for (int i=0; i < len; i++)
                num[i] = 1;
        } else {
            int average = len / k, remain = len % k;
            for (int i=0; i < k; i++) {
                num[i] = average;
                if (remain-- > 0) num[i]++;
            }
        }

        // 分隔链表
        vector<ListNode*> v;
        for (int i=0; i < k; i++) {
            ListNode *head = new ListNode(0), *tail = head;
            tail->next = root;
            while (num[i]--)
                tail = tail->next;

            root = tail->next;
            tail->next = nullptr;

            v.push_back(head->next);
        }

        return v;
    }
};
