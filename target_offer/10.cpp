# include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int F[n+1];
        F[0] = 0;
        F[1] = 1;
        int cur = 2;
        while (cur <= n) {
            F[cur] = (F[cur-1] + F[cur-2]) % 1000000007;
            cur++;
        }
        return F[n];
    }
};