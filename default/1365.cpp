# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
# include <map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        set<int> temp;
        for (int num : nums) {
            temp.insert(num);
        }
        sort(temp.begin(), temp.end());
        map<int, int> mp;
        int idx = 0;
        for (auto lt=temp.begin(); lt!=temp.end(); lt++) {
            mp[*lt] = idx;
            idx++;
        }
        for (int i = 0; i < nums.size(); i++) {

        }

    }
};