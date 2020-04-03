# include <iostream>
# include <vector>
# include <string>
# include <ctype.h>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> v;
        backTracking(v, S, 0);
        return v;
    }

    void backTracking(vector<string>& v, string& s, int idx) {
        if (idx == s.length()) {
            v.push_back(s);
            return ;
        }

        backTracking(v, s, idx+1);

        if (isalpha(s[idx])) {
            s[idx] = islower(s[idx])? s[idx]-32 : s[idx]+32;
            backTracking(v, s, idx+1);
        }
    }
};