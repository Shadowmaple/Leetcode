# include <iostream>
# include <ctype.h>
# include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (!isValid(s[i]) && i < j) i++;
            while (!isValid(s[j]) && i < j) j--;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }

    bool isValid(char c) {
        c = tolower(c);
        char a[] = "aeiou";
        for (int i = 0; i < 6; i++)
            if (a[i] == c) return true;
        return false;
    }
};