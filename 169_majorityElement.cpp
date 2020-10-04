# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int len = nums.size() / 2;
        for (int num : nums) {
            mp[num]++;

            if (mp[num] > len) return num;
        }
        return 0;
    }
};