# include <iostream>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n < 2) return 1;
        int num[n+1];
        num[1] = 1;
        num[2] = 2;
        for (int i = 3; i < n+1; i++) {
            num[i] = (num[i-1] + num[i-2]) % 1000000007;
        }
        return num[n];
    }
};