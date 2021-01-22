# include <iostream>
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int count = 0;
        int redunant = 0;
        for (auto it=mp.begin(); it != mp.end(); it++) {
            int num = it->second;
            if (num % 2 == 0) count += num;
            else {
                count += num-1;
                redunant++;
            }
        }
        if (redunant) count++;
        return count;
    }
};