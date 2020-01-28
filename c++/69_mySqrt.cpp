# include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int left = 1, right = x / 2 + 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid < x / mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};