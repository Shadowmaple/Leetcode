# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = 0;
        int len = 0, count = 0;
        int num[128] = {0};
        num['a'] = num['e'] = num['i'] = num['o'] = num['u'] = 1;
        while (r < s.length()) {
            if (num[s[r]]) count++;
            while (r - l + 1 > k) {
                if (num[s[l]]) count--;
                l++;
            }
            len = max(len, count);
            r++;
        }
        return len;
    }
};