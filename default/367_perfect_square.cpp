# include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 2, r = num / 2, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid == num / mid && num % mid == 0) return true;
            else if (mid < num / mid) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};