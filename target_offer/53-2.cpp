# include <iostream>
# include <vector>
using namespace std;

// 二分法，不断压缩边界
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == mid) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};