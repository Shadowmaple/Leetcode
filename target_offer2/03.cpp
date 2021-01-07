# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

// 哈希表
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> visited;
        for (int num : nums) {
            if (visited.count(num)) return num;
            visited.insert(num);
        }
        return 0;
    }
};

// 原地排序
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) return nums[i];
        }
        return 0;
    }
};

// 原地交换
// 时间O(n), 空间O(1)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) i++;
            else if (nums[nums[i]] == nums[i]) return nums[i];
            else swap(nums[i], nums[nums[i]]);
        }
        return 0;
    }
};