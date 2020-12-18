# include <iostream>
# include <map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> mp;
        for (auto n : nums) {
            if (mp[n]) return n;
            mp[n]++;
        }
        return 0;
    }
};
