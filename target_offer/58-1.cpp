# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int l = 0, r = 0;
        while (r < s.length()) {
            while (r < s.length() && s[r] == ' ') r++;
            l = r;
            while (r < s.length() && s[r] != ' ') r++;
            if (l == r) break;
            result = s.substr(l, r-l) + ' ' + result;
        }
        // 删除空格
        result.erase(result.end()-1);
        return result;
    }
};