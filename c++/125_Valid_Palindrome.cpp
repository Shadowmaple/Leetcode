# include <iostream>
# include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;
            if (i >= j) break;
            if (tolower(s[i++]) != towlower(s[j--])) return false;
        }
        return true;
    }
};