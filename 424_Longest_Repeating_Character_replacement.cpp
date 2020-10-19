# include <iostream>
using namespace std;

// 滑动窗口
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxNum = 0;
        int l = 0, r = 0;
        int num[26] = {0};
        int len = s.length();
        for (; r < len; r++) {
            num[s[r] - 'A']++;
            maxNum = max(maxNum, num[s[r]-'A']);
            if (maxNum + k < r - l + 1) {
                num[s[l] - 'A']--;
                l++;
            }
        }
        return r - l;
    }
};
