# include <iostream>
# include <set>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s == "") return ' ';

        int temp[128] = {0};
        for (char c : s)
            temp[c]++;
        for (char c : s)
            if (temp[c] == 1) return c;
        return ' ';
    }
};