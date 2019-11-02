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
    int numComponents(ListNode* head, vector<int>& G) {
        int N = 0;
        ListNode *p = head;
        while (p) {
            N++;
            p = p->next;
        }

        int *num = new int[N]{0};
        while (!G.empty()) {
            num[G.back()] = 1;
            G.pop_back();
        }

        int sum = 0, count = 0;
        while (head) {
            if (num[head->val])
                count++;
            else if (count) {
                sum++;
                count = 0;
            }
            head = head->next;
        }
        if (count) sum++;
        return sum;
    }
};
