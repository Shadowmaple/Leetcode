# include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int n = 1;
        while (n <= x / n) {
            n++;
        }
        return n - 1;
    }
};