# include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (nums.at(n - 1) < target)
            return n;
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums.at(mid) == target)
                return mid;
            else if (nums.at(mid) < target)
                left++;
            else
                right--;
        }
        return mid;
    }
};
