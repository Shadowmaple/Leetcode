# include <iostream>
# include <set>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st{'a', 'e', 'i', 'o','u','A','E','I','O','U'};
        int num1 = 0, num2 = 0;
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (st.count(s[l++]) == 1) num1++;
            if (st.count(s[r--]) == 1) num2++;
        }
        return num1 == num2;
    }
};