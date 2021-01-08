# include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n == -1) return 1 / x;

        double cur = myPow(x, n / 2);
        if (n & 1) return n > 0 ? cur * cur * x : cur * cur * 1/x;
        return cur * cur;
    }
};