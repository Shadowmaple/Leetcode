# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int count = 0;
        map<int, int> mp;
        for (int n : nums) {
            if (mp.find(n) == mp.end())
                mp[n] = 1;
            else mp[n]++;
        }
        for (auto it = begin(mp); it != end(mp); it++) {
            if (k == 0) {
                if (it->second > 1) count++;
            } else if (mp.find(it->first + k) != end(mp))
                count++;
        }
        return count;
    }
};