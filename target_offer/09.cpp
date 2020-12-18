# include <iostream>
# include <stack>
using namespace std;

class CQueue {
public:
    stack<int> skIn, skOut;
    CQueue() {
    }

    void appendTail(int value) {
        while (!skOut.empty()) {
            skIn.push(skOut.top());
            skOut.pop();
        }
        skIn.push(value);
    }

    int deleteHead() {
        while (!skIn.empty()) {
            skOut.push(skIn.top());
            skIn.pop();
        }
        if (skOut.empty()) return -1;
        int num = skOut.top();
        skOut.pop();
        return num;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
