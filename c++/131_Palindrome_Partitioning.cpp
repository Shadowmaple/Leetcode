# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> v;
    vector<vector<string>> partition(string s) {
        vector<string> mth;
        backTracking(mth, s, 0);
        return v;
    }

    void backTracking(vector<string>& mth, string& s, int idx) {
        if (idx == s.length()) {
            v.push_back(mth);
            return ;
        }

        for (int i = idx; i < s.length(); i++) {
            // 是否回文
            bool pdr = true;
            for (int x=idx, y=i; x < y; x++, y--) {
                if (s[x] != s[y]) {
                    pdr = false;
                    break;
                }
            }
            if (!pdr) continue;

            // string sub = s.substr(idx, i-idx+1);

            mth.push_back(s.substr(idx, i-idx+1));
            backTracking(mth, s, i+1);
            mth.pop_back();
        }
    }
};