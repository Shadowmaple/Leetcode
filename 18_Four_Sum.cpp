# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> v;
        if (!size) return v;
        sort(begin(nums), end(nums));
        for (int i = 0; i < size-3; i++) {
            if (i && nums[i] == nums[i-1]) continue; // 确保i改变，去重
            for (int j = i+1; j < size-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue; // 确保j改变
                int l = j + 1, r = size-1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        v.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++; // 确保l改变
                        while (l < r && nums[r] == nums[r-1]) r--; // 确保r改变
                        l++;
                        r--;
                    } else if (sum < target) l++;
                    else r--;
                }
            }
        }
        return v;
    }
};