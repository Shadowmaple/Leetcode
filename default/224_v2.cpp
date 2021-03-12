# include <iostream>
# include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> sk;

        int res = 0;
        int sign = 1;
        int idx = 0;
        while (idx < s.length()) {
            if (s[idx] == ' ') {
                idx++;
                continue;
            }
            if (s[idx] <= '9' && s[idx] >= '0') {
                int num = s[idx] - '0';
                while (s[idx+1] <= '9' && s[idx+1] >= '0') {
                    num = num * 10 + (s[idx+1] - '0');
                    idx++;
                }
                res += num * sign;
            } else if (s[idx] == '+' || s[idx] == '-') {
                sign = s[idx] == '+' ? 1 : -1;
            } else if (s[idx] == '(') {
                sk.push(res);
                sk.push(sign);
                res = 0;
                sign = 1;
            } else if (s[idx] == ')') {
                sign = sk.top();
                sk.pop();
                res = sign * res + sk.top();
                sk.pop();
            }
            idx++;
        }

        return res;
    }
};