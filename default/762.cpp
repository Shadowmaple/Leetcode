# include <iostream>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) {
            int num = 0, x = 1;
            while (x <= i) {
                if (x & i) num++;
                x <<= 1;
            }
            if (check(num)) res++;
        }
        return res;
    }

    bool check(int num) {
        if (num == 2 || num == 3) return true;
        if (num == 1 || num % 2 == 0) return false;

        for (int i = 3; i <= num/2; i+=2) {
            if (num % i == 0) return false;
        }
        return true;
    }
};