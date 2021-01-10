# include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int res = (2*week+1+day)*day >> 1;

        for (int i = 0; i < week; i++)
            res += 28 + i * 7;

        return res;
    }
};