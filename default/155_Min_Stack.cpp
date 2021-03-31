# include <stack>
using namespace std;

// 辅助栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (minStk.empty() || x <= minStk.top())
            minStk.push(x);
    }

    void pop() {
        if (stk.top() == minStk.top())
            minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};


// 
class MinStack2 {
public:
    stack<long> sk;
    int minVal;
    /** initialize your data structure here. */
    MinStack() {
        minVal = 0;
    }
    
    void push(int val) {
        if (sk.empty()) {
            sk.push(0);
            minVal = val;
            return ;
        }
        long diff = long(val) - long(minVal);
        if (diff < 0) minVal = val;
        sk.push(diff);
    }
    
    void pop() {
        if (sk.top() < 0) {
            minVal = minVal - sk.top();
        }
        sk.pop();
    }
    
    int top() {
        if (sk.top() < 0) return minVal;
        return sk.top() + minVal;
    }
    
    int getMin() {
        return minVal; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

