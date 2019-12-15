# include <vector>
using namespace std;

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