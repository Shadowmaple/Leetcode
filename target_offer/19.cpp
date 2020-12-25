# include <iostream>
using namespace std;

// 正则表达式匹配，未通过
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }

    bool match(string& s, string& p, int x, int y) {
        if (y == p.length())
            return x == s.length();

        bool isMatched = y < s.length() && (s[x] == p[y] || p[y] == '.');

        // * 匹配
        if (y < p.length()-1 && p[y+1] == '*') {
            // 当前字符匹配成功时
            if (isMatched) {
                // 持续匹配当前 p 的字符
                // 或 0 匹配，忽略 p 当前字符
                return match(s, p, x+1, y) || match(s, p, x, y+2);
            }
            // 0 匹配，忽略 p 当前的字符
            return match(s, p, x, y+2);
        }

        // 当前字符匹配成功时
        if (isMatched)
            return match(s, p, x+1, y+1);

        return false;
    }
};