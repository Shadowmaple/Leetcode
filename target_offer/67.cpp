# include <iostream>
using namespace std;

// Debug >= n 次，修修补补，最讨厌这种题了
class Solution {
public:
    int strToInt(string str) {
        int res = 0, len = str.length();
        bool neg = true;
        int idx = 0;
        while (idx < len && str[idx] == ' ')
            idx++;
        if (idx == len) return 0;
        if (str[idx] == '-') {
            neg = false;
            idx++;
        } else if (str[idx] == '+') idx++;
        else if (str[idx] < '0' || str[idx] > '9')
            return 0;

        int flag = 0; // 负数欠一位
        while (idx < len && str[idx] >= '0' && str[idx] <= '9') {
            int n = str[idx] - '0';
            if (neg && res > (INT32_MAX-n)/10)
                return INT32_MAX;
            else if (!neg && -res < (INT32_MIN+n)/10)
                return INT32_MIN;
            if (!neg && -res == (INT32_MIN+n)/10) {
                flag = n;
                res *= 10;
            } else res = res * 10 + n;

            idx++;
        }
        if (!neg) res = -res - flag;
        return res;
    }
};