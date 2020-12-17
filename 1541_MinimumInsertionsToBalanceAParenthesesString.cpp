# include <iostream>
# include <stack>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> sk;
        int count = 0;
        int i = 0;
        int len = s.length();
        while (!sk.empty() || i < len) {
            if (i == len) {
                sk.pop();
                count += 2;
                continue;
            }
            char cur = s[i++];
            if (cur == '(') {
                sk.push(cur);
                continue;
            }
            // 单个 '('
            if (i == len || s[i] != ')')
                count++;
            else i++;
            // 用 '(' 匹配
            if (sk.empty() || sk.top() != '(')
                count++;
            else  sk.pop();
        }
        return count;
    }
};