# include <iostream>
# include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        auto cur = head;
        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        swap(v[k-1], v[v.size()-k]);
        cur = head;
        int i = 0;
        while (cur) {
            cur->val = v[i++];
            cur = cur->next;
        }
        return head;
    }
};