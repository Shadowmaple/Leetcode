# include <iostream>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n >= s.length()) return s;
        return s.substr(n, s.length()) + s.substr(0, n);
    }
};