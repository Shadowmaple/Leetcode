# include <iostream>
using namespace std;

// 牛逼的质数筛选法，多学学
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        int count = 0;
        int num[n];
        num[2] = 1;
        for (int i = 0 ; i < n; i++) num[i] = 1;
        for (int i = 2; i < n; i++) {
            if (!num[i]) continue;
            for (int x = 2*i; x < n; x += i) {
                num[x] = 0;
            }
            count++;
        }
        return count;
    }
};