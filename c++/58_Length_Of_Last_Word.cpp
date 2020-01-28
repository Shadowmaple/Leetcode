# include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0, m = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] != ' ') {
                m++;
                continue;
            }
            n = (n >= m) ? n : m;
            if (n) break;
            m = 0;
        }
        n = (n >= m) ? n : m;
        return n;
    }
};