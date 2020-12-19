# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        string res;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') res += "%20";
            else res += s[i];
        }
        return res;
    }
};