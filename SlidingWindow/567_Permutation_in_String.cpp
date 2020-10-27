# include <iostream>
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0;
        map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }
        int len = s1.length();
        for (; r < s2.length(); r++) {
            if (!mp.count(s2[r])) continue;
            mp[s2[r]]--;

            if (r-l+1 < len) continue;

            while (r-l+1 > len || !mp.count(s2[l])) {
                if (mp.count(s2[l])) mp[s2[l]]++;
                l++;
            }
            if (r-l+1 < len) continue;

            bool flag = true;
            for (auto it=mp.begin(); it != mp.end(); it++) {
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