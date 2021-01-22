# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = 0, m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                r++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[m]);
                m++;
                r++;
            } else {
                swap(nums[i], nums[l]);
                if (l != m) swap(nums[i], nums[m]);
                l++;
                m++;
                r++;
            }
        }
    }
};