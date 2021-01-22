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

class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int count = 0;
        sort(begin(nums), end(nums));
        int i = 0, j = 1;
        while (j < nums.size()) {
            if (nums[j] - nums[i] == k) {
                count++;
                i++;
                j++;
            } else if (nums[j] - nums[i] < k)
                j++;
            else i++;

            while (j < nums.size() && nums[j] == nums[j-1])
                j++;
            while (i < nums.size() && i > 0 && nums[i] == nums[i-1])
                i++;
            if (i == j) j++;
        }
        return count;
    }
};