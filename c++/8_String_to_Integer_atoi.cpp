# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long num = 0;
        int len = 0;
        string s;
        bool minus = false, hasChar = false;
        for (char c : str) {
            if (c > '9' || c < '0') {
                if (len) break;
                if (hasChar) return 0;
                if (c == ' ') continue;
                else if (c == '+') {
                    hasChar = true;
                    continue;
                } else if (c == '-') {
                    minus = hasChar = true;
                    continue;
                }
                return 0;
            }
            len++;
            num = num * 10 + (c - '0');
            if (num > 2147483647 && !minus || num > 2147483648)
                break;
        }
        if (num > 2147483647 && !minus) return 2147483647;
        else if (num > 2147483648) return -2147483648;

        if (minus) return -num;
        return num;
    }
};