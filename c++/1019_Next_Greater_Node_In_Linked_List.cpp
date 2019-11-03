# include <iostream>
# include <vector>
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        // 第一个是下标，第二个是值
        stack<pair<int, int>> stk;
        int index = 0;

        while (head) {
            v.push_back(0);
            while (!stk.empty() && head->val > stk.top().second) {
                v[stk.top().first] = head->val;
                stk.pop();
            }
            stk.push(make_pair(index++, head->val));

            head = head->next;
        }
        return v;
    }
};
