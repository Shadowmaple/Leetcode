# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int hash[150] = {0};
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]-'0']++;
            hash[t[i]-'0']--;
        }
        for (int i = 'a'-'0'; i < 'z'-'0'; i++)
            if (hash[i]) return false;
        return true;
    }
};