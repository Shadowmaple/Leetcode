# include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        while (s[r] == ' ') r++;
        l = r;
        string res;
        while (r < s.length()) {
            while (r < s.length() && s[r] != ' ') r++;
            res = s.substr(l, r-l) + " " + res;
            while (r < s.length() && s[r] == ' ') r++;
            l = r;
        }
        return res.substr(0, res.length()-1);
    }
};