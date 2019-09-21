# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) {
            return len;
        }
        int count = 1, pre = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] <= nums[pre]) {
                continue;
            }
            pre++;
            nums[pre] = nums[i];
            count++;
        }
        return count;
    }
};

int main() {

}