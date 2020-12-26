# include <iostream>
# include <stack>
# include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;

        stack<int> sk;
        int pushIdx = 0, popIdx = 0;

        while (popIdx < popped.size()) {
            if (!sk.empty() && sk.top() == popped[popIdx]) {
                sk.pop();
                popIdx++;
            } else if (pushIdx < pushed.size() && pushed[pushIdx] == popped[popIdx]) {
                pushIdx++;
                popIdx++;
            } else {
                if (pushIdx >= pushed.size()) return false;
                sk.push(pushed[pushIdx++]);
            }
        }
        return true;
    }
};