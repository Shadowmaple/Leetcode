# include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'A') a++;
            else if (s[i] == 'L' && i > 1 && s[i-1] == 'L' && s[i-2] == 'L')
                return false;

            if (a > 1) return false;
        }
        return true;
    }
};