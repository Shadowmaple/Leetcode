# include <iostream>
# include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        int len = s.length();
        for (int i = len-1; i >= 0; i--) {
            num += (s[i] - 'A' + 1) * pow(26, len-i-1);
        }
        return num;
    }
};
