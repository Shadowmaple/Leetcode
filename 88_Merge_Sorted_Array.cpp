# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && (j >= n || nums1.at(i) <= nums2.at(j)))
                nums.push_back(nums1.at(i++));
            else if (j < n && (i >= m || nums1.at(i) > nums2.at(j)))
                nums.push_back(nums2.at(j++));
        }
        nums1 = nums;
    }
};
