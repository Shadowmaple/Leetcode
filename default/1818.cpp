# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        int cur = 0;
        long sum = 0;
        // auto nums3 = vector(nums1);
        vector<int> nums3(nums1);
        sort(nums3.begin(), nums3.end());
        for (int i = 0; i < len; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum += diff;
            int l = 0, r = len-1;
            while (l <= r) {
                int mid = l+(r-l)/2;
                if (nums3[mid] == nums2[i]) {
                    r = mid;
                    break;
                }
                if (nums3[mid] < nums2[i]) l = mid + 1;
                else r = mid - 1;
            }
            int diff2 = diff;
            if (r >= 0) diff2 = abs(nums3[r] - nums2[i]);
            if (l < len) diff2 = min(diff2, abs(nums3[l] - nums2[i]));
            cur = max(cur, diff-diff2);
        }
        sum -= cur;
        return sum % 1000000007;
    }
};