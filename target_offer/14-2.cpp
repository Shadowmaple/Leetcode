# include <iostream>
# include <math.h>
using namespace std;

// 贪心算法，无法用 DP，会溢出
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 2) return 1;
        else if (n == 3) return 2;

        int count = n / 3;
        long res = 1;
        if (n % 3 == 1) {
            res = 2*2;
            count--;
        } else if (n % 3) {
            res = n % 3;
        }

        while (count--) res = res * 3 % 1000000007;

        return res;
    }
};