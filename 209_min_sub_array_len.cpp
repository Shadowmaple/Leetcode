# include <iostream>
# include <vector>
using namespace std;

// 双指针，滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int arr = size + 1;
        int sum = 0, left = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            while (sum >= s) {
                arr = min(arr, i - left + 1);
                sum -= nums[left++];
            }
        }
        return (arr != size + 1) ? arr : 0;
    }
};