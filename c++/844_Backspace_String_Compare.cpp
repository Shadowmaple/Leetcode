# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1;
        for (char c : S) {
            if (c != '#') s1 += c;
            else if (!s1.empty()) s1.pop_back();
        }
        S = s1;
        s1.clear();
        for (char c : T) {
            if (c != '#') s1 += c;
            else if (!s1.empty()) s1.pop_back();
        }
        if (S == s1) return true;
        return false;
    }
};