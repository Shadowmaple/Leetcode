# include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        else if (n == 1) return x;

        long temp = n;
        if (n < 0) {
            temp = abs(temp);
            x = 1 / x;
        }

        double num = myPow(x, temp >> 1);
        double res = num * num;

        // 奇数
        if (temp & 1) res *= x;

        return res;
    }
};