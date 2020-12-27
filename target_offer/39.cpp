# include <iostream>
# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
            if (mp[n] > nums.size() > 1) return n;
        }
        return 0;
    }
};

// 摩尔投票法
// 也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，
// 最后活下来的值都是相同的，即要求的结果
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n, count = 0;
        for (auto num : nums) {
            if (!count) {
                count = 1;
                n = num;
                continue;
            }
            if (num != n) count--;
            else count++;
        }
        return n;
    }
};