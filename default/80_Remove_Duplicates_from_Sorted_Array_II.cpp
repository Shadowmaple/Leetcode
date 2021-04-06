# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it=nums.begin(); it < nums.end();) {
            if (it > nums.begin()+1 && *(it) == *(it-1) && *(it) == *(it-2))
                nums.erase(it);
            else it++;
        }
        return nums.size();
    }
};

// 原地删除，双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1, r = 1;
        int cur = nums[0], count = 1;
        while (r < nums.size()) {
            if (nums[r] != cur) {
                cur = nums[r];
                nums[l++] = nums[r];
                count = 1;
            } else if (count < 2) {
                nums[l++] = nums[r];
                count++;
            }
            r++;
        }
        return l;
    }
};
