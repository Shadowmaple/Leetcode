# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool first = true;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                first = false;
                continue;
            }
            if (first) return nums[i];
            first = true;
        }
        return nums[nums.size()-1];
    }
};

// 异或运算符
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};