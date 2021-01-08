# include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        auto cur = head;
        while (cur) {
            Node* next = new Node(cur->val);
            next->next = cur->next;
            cur->next = next;
            cur = next->next;
        }

        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node* newHead = head->next;
        auto origin = head;
        cur = newHead;
        while (cur && cur->next) {
            origin->next = cur->next;
            cur->next = cur->next->next;
            origin = origin->next;
            cur = cur->next;
        }
        origin->next = nullptr;
        return newHead;
    }
};