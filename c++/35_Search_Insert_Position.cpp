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
        int i = 0;
        for (; i < nums.size(); i++) {
            if (target <= nums.at(i)) {
                break;
            }
        }
        return i;
    }
};
