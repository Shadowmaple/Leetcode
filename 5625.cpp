# include <iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while (n > 1) {
            count += n / 2;
            if (n % 2) count += 1;
            n /= 2;
        }
        return count;
    }
};