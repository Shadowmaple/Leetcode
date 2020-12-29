# include <iostream>
# include <math.h>
using namespace std;

// 脑壳疼
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;

        n -= 10;
        // 位于几位数
        int digit = 2;
        for (; ; digit++) {
            long num = getIdxByDigit(digit);
            if (n < num) break;
            n -= num;
        }
        // 数字中的序列号
        int idx = n % digit;
        // 该n位对应的数字
        int num = n / digit + pow(10, digit-1);

        // 倒序的序列号
        idx = digit - idx - 1;
        while (idx-- > 0) num /= 10;

        return num % 10;
    }

    // 获取位数的长度
    long getIdxByDigit(int n) {
        return 9 * pow(10, n-1) * n;
    }
};