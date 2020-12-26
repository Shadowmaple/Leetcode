# include <iostream>
# include <stack>
using namespace std;

// 单调栈
// 还可以尝试其它数据结构，比如链表，思维有点受限了
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> sk;
    stack<int> minSk;
    MinStack() {}

    void push(int x) {
        sk.push(x);
        if (minSk.empty() || minSk.top() >= x)
            minSk.push(x);
    }

    void pop() {
        int cur = sk.top();
        if (cur == minSk.top())
            minSk.pop();
        sk.pop();
    }

    int top() {
        return sk.top();
    }

    int min() {
        return minSk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */