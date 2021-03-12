# include <iostream>
# include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> sk;
        stack<char> signSk;

        int idx = 0;
        while (idx < s.length()) {
            if (s[idx] == ' ') {
                idx++;
                continue;
            }
            if (s[idx] <= '9' && s[idx] >= '0') {
                int num = 0;
                while (s[idx] <= '9' && s[idx] >= '0') {
                    num = num * 10 + (s[idx] - '0');
                    idx++;
                }
                if (!signSk.empty() && (signSk.top() == '+' || signSk.top() == '-')) {
                    num = signSk.top() == '-' ? -num : num;
                    signSk.pop();
                    if (!sk.empty()) {
                        num = sk.top() + num;
                        sk.pop();
                    }
                }
                sk.push(num);
            } else if (s[idx] == '+' || s[idx] == '-' || s[idx] == '(') {
                signSk.push(s[idx++]);
            } else if (s[idx] == ')') {
                signSk.pop();
                if (signSk.empty()) {
                    idx++;
                    continue;
                }
                int num = sk.top();
                sk.pop();
                num = signSk.top() == '-' ? -num : num;
                signSk.pop();
                if (!sk.empty()) {
                    num = sk.top() + num;
                    sk.pop();
                }
                sk.push(num);
                idx++;
            }
        }

        return sk.top();
    }
};

int main() {
    Solution s;
    cout << s.calculate("1 + 1") << endl;
    return 0;
}