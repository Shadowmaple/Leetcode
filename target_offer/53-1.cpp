# include <iostream>
# include <vector>
using namespace std;

// 二分查找，
// 找到一个targe，再向左向右扫面
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
        int l = 0, r = nums.size()-1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) break;
            if (nums[mid] > target) r = mid-1;
            else l = mid + 1;
        }
        if (nums[mid] != target) return 0;
        int count = 0;
        for (int i = mid-1; i >= 0 && nums[i] == target; i--)
            count++;
        for (int i = mid+1; i < nums.size() && nums[i] == target; i++)
            count++;
        return count + 1;
    }
};

// 二分查找
// 用两个二分分别查找左右边界
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return 0;

        int i = 0, j = nums.size()-1;
        // 查找右边界
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        // 未找到
        if (i && nums[i-1] != target) return 0;
        int r = i;
        i = 0;
        j = nums.size()-1;
        // 查找左边界
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) j = mid - 1;
            else i = mid + 1;
        }
        int l = j;
        // l和r均指向开区间
        return r - l - 1;
    }
};