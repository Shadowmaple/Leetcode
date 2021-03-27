# include <iostream>
# include <vector>
using namepace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSearch(nums, k, 0, nums.size()-1);
    }

    int quickSearch(vector<int>& nums, int k, int left, int right) {
        int l = left, r = right;
        int key = nums[l];
        while (l < r) {
            while (l < r && nums[r] < key) r--;
            if (l >= r) break;
            nums[l++] = nums[r];
            while (l < r && nums[l] >= key) l++;
            if (l >= r) break;
            nums[r--] = nums[l];
        }
        nums[l] = key;
        if (l == k-1) return nums[l];
        if (l > k-1) return quickSearch(nums, k, left, l-1);
        return quickSearch(nums,k, l+1, right);
    } 
};

