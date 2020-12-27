# include <iostream>
# include <map>
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

// 哈希表
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* newHead = new Node(0);
        Node *cur = newHead, *temp = head;
        map<Node*, Node*> mp;
        while (temp) {
            cur->next = new Node(temp->val);
            cur = cur->next;

            mp[temp] = cur;

            temp = temp->next;
        }

        temp = head;
        while (temp) {
            if (temp->random)
                mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return newHead->next;
    }
};

// 链表原地修改，大佬的思维
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 构造链表，1->1'->2->2'
        Node* cur = head, *temp;
        while (cur) {
            temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }

        // random 指针
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 将链表拆分
        Node* old = head;
        Node* newHead = head->next;
        cur = newHead;
        while (old) {
            old->next = cur->next;
            old = old->next;
            if (cur->next) {
                cur->next = old->next;
                cur = cur->next;
            }
        }
        return newHead;
    }
};