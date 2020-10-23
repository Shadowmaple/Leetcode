# include <iostream>
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0;
        map<char, int> mp, cur;
        for (char c : s1) {
            mp[c]++;
            cur[c]++;
        }
        int len = s1.length();
        for (; r < s2.length(); r++) {
            if (mp[s2[r]] == 0) continue;
            cur[s2[r]]--;

            while (r-l+1 > len || mp[s2[l]] == 0) {
                if (mp[s2[l]]) cur[s2[l]]++;
                l++;
            }
            if (r-l+1 < len) continue;

            bool flag = true;
            for (auto it=cur.begin(); it != cur.end(); it++) {
                if (it->second > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};