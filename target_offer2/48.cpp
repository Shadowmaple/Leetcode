# include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0;
        int visited[128] = {0};
        while (r < s.length()) {
            if (visited[s[r]]) {
                while (l < r && s[l] != s[r]) {
                    visited[s[l]] = 0;
                    l++;
                }
                l++;
            }
            visited[s[r]] = 1;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};