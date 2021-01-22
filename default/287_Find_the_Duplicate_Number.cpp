# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for (int n : nums) {
            if (count[n]) return n;
            else count[n]++;
        }
        return 0;
    }
};