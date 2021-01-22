# include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int len1 = s.length(), len2 = t.length();
        for (int j = 0; j < len2 && i < len1; j++) {
            if (t[j] == s[i]) i++;
        }
        return i == len1;
    }
};