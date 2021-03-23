# include <iostream>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node(): key(0), val(0), next(nullptr) {}
    Node(int key, int value): key(key), val(value), next(nullptr) {}
};

class LRUCache {
public:
    Node* lru;
    int cap;
    int len;
    LRUCache(int capacity) {
        lru = new Node();
        cap = capacity;
        len = 0;
    }
    
    int get(int key) {
        auto cur = lru;
        while (cur->next) {
            if (cur->next->key == key) break;
            cur = cur->next;
        }
        if (cur->next == nullptr) return -1;

        // 将节点提到首部
        auto tar = cur->next;
        cur->next = tar->next;
        tar->next = lru->next;
        lru->next = tar;

        return tar->val;
    }
    
    void put(int key, int value) {
        auto cur = lru;
        while (cur->next) {
            if (cur->next->key == key) break;
            cur = cur->next;
        }
        if (cur->next) {
            cur->next->val = value;
            // 将节点提到首部
            auto tar = cur->next;
            cur->next = tar->next;
            tar->next = lru->next;
            lru->next = tar;
            return ;
        }

        // 删除尾节点
        if (len == cap) {
            cur = lru;
            while (cur->next->next) {
                cur = cur->next;
            }
            cur->next = nullptr;
            len--;
        }

        cur = new Node(key, value);
        cur->next = lru->next;
        lru->next = cur;
        len++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
