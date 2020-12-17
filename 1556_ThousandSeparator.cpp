# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (!n) return "0";
        int step = 0;
        string s;
        while (n) {
            char x = n % 10 + '0';
            n /= 10;
            if (step++ && step++ % 3 == 0) s = '.' + s;
            s = x + s;
        }
        return s;
    }
};