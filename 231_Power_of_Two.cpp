# include <iostream>
using namespace std;

// 神仙解法，位运算
class Solution {
public:
    bool isPowerOfTwo(int n) {
		return n > 0 && !(n & n-1);
    }
};
