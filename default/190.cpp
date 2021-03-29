# include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;
        while (count--) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};
