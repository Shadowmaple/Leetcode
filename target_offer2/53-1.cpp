# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = 0;
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        low = r + 1;

        l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] <= target) l = mid+1;
            else r = mid-1;
        }
        high = l - 1;
        return high - low + 1;
    }
};
