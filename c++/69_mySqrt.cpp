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

// 牛顿迭代法
class Solution2 {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        long n = x;
        while (n > x / n) {
            n = (n + (x / n)) / 2; //公式
        }
        return int(n);
    }
};