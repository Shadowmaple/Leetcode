# include <iostream>
# include <vector>
using namespace std;

// 异或
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (auto num : nums)
            temp ^= num;
        // 找到为 1 的位
        int mask = 1;
        while ((mask & temp) == 0) mask <<= 1;

        // 根据 mask 分两个组，在两个组中异或获取值
        int a = 0, b = 0;
        for (auto num : nums) {
            if (num & mask) a ^= num;
            else b ^= num;
        }
        return vector<int>{a, b};
    }
};