# include <iostream>
# include <vector>
using namespace std;

// 归并思想-_-
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        return mergeSort(nums, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if (l == r) return 0;

        int mid = l + (r - l) / 2;
        int leftNum = mergeSort(nums, l, mid);
        int rightNum = mergeSort(nums, mid+1, r);
        int mergeNum = merge(nums, l, mid, r);

        return leftNum + rightNum + mergeNum;
    }

    int merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp = vector<int>(r-l+1);
        int i = l, j = mid+1;
        int k = 0;
        int count = 0;
        while (i <= mid || j <= r) {
            if (i == mid + 1) {
                temp[k++] = nums[j++];
            } else if (j == r + 1) {
                temp[k++] = nums[i++];
            } else if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                count += mid - i + 1;
            }
        }
        k--;
        while (k >= 0) nums[r--] = temp[k--];

        return count;
    }
};

int main() {
    vector<int> nums{7,5,6,4};
    Solution s;
    int n = s.reversePairs(nums);
    cout << n << endl;
    return 0;
}