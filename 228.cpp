# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) return vector<string>{};
        vector<string> res;
        int l = 0, r = 0;
        for (; r < nums.size(); r++) {
            if (l == r || nums[r]-1 == nums[r-1]) continue;
            if (r - l == 1) {
                res.push_back(to_string(nums[l]));
            } else {
                string s = to_string(nums[l]) + "->" + to_string(nums[r-1]);
                res.push_back(s);
            }
            l = r;
        }
        if (r - l == 1)
            res.push_back(to_string(nums[l]));
        else
            res.push_back(to_string(nums[l]) + "->" + to_string(nums[r-1]));

        return res;
    }
};