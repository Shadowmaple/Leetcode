# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0, count = 0;
        int l = 0, r = 0;
        int cost = 0;
        while (r < s.length()) {
            int curCost = abs(s[r] - t[r]);
            if (curCost > maxCost) {
                r++;
                count = 0;
                l = r;
                cost = 0;
                continue;
            }
            if (curCost + cost <= maxCost) {
                count++;
                cost += curCost;
                r++;
                len = max(len, count);
                continue;
            }
            cost -= abs(s[l] - t[l]);
            count--;
            l++;
        }
        return len;
    }
};

// better, quicker and more concise solution
class Solution2 {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0, count = 0;
        int l = 0, r = 0;
        int cost = 0;
        while (r < s.length()) {
            cost += abs(s[r] - t[r]);
            while (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};