# include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int stairs[n + 1] = {0, 1, 2};
        for (int i = 3; i <= n; i++) {
            stairs[i] = stairs[i - 2] + stairs[i - 1];
        }
        return stairs[n];
    }
};