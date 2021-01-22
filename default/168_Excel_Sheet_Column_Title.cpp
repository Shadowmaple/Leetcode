# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            // n-- 是精髓，看了讨论才做出来的
            n--;
            s = char(n % 26 - 1 + 'A') + s;
            n /= 26;
        }
        return s;
    }
};