# include <iostream>
# include <stack>
# include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int l = 0, r = 0;
        while (r < popped.size()) {
            while (sk.empty() || popped[r] != sk.top()) {
                if (l >= pushed.size()) return false;
                sk.push(pushed[l++]);
            }
            sk.pop();
            r++;
        }
        return true;
    }
};