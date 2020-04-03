# include <iostream>
# include <vector>
using namespace std;

// 暴力法，很low，O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            max = sum > max ? sum : max;
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                max = sum > max ? sum : max;
            }
        }
        return max;
    }
};

// 贪心算法，O(n)
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result = max(result, sum);
            if (sum < 0) sum = 0;
        }
        return result;
    }
};